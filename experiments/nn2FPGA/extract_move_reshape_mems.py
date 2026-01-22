#!/usr/bin/env python3
"""
extract_move_reshape_mems.py

Usage:
  python extract_move_reshape_mems.py input.cpp output.cpp --func resnet8 [--mems memories.txt] [--tb testbench.cpp]

Pipeline:
1) Remove all '#pragma HLS INTERFACE ...' pragmas.
2) Extract memories associated with '#pragma HLS ARRAY_RESHAPE' and remove ONLY the
   corresponding array declaration lines from the file (keep reshape pragmas).
3) Replace NHWCToStream with mm2s and inject in_data into the interface.
4) Replace StreamToNHWC with s2mm and inject out_data into the interface.
5) Replace the top function signature entirely (NO old params kept).
6) Inject: #include "utils/stream_utils.hpp"
7) Optionally generate a testbench.
"""

import argparse
import re
from collections import OrderedDict
from typing import List, Tuple, Dict, Set, Optional

RESHAPE_PRAGMA_RE = re.compile(r'^\s*#\s*pragma\s+HLS\s+ARRAY_RESHAPE\b')
INTERFACE_PRAGMA_RE = re.compile(r'^\s*#\s*pragma\s+HLS\s+INTERFACE\b')

ARRAY_DECL_RE = re.compile(
    r"""^\s*
        (?:[A-Za-z_].*?)
        \b([A-Za-z_]\w*)\b
        \s*(\[[^\]]*\])\s*
        (?:\s*(\[[^\]]*\]\s*))*
        \s*;
        \s*$
        """,
    re.VERBOSE
)

FUNC_START_RE_TEMPLATE = r'\bvoid\s+{fname}\s*\('


def parse_args():
    p = argparse.ArgumentParser()
    p.add_argument("input_cpp")
    p.add_argument("output_cpp")
    p.add_argument("--func", required=True)
    p.add_argument("--mems", default=None)
    p.add_argument("--tb", default=None)
    return p.parse_args()


# -------------------------------------------------------------------
# Utility helpers
# -------------------------------------------------------------------

def strip_cpp_line_comments(s: str) -> str:
    out = []
    for l in s.splitlines():
        out.append(l.split("//", 1)[0] if "//" in l else l)
    return "\n".join(out)


def split_top_level_commas(s: str) -> List[str]:
    parts, cur = [], []
    da = dp = db = 0
    for c in s:
        if c == "<": da += 1
        elif c == ">": da -= 1
        elif c == "(": dp += 1
        elif c == ")": dp -= 1
        elif c == "[": db += 1
        elif c == "]": db -= 1

        if c == "," and da == dp == db == 0:
            parts.append("".join(cur).strip())
            cur = []
        else:
            cur.append(c)

    if cur:
        parts.append("".join(cur).strip())
    return [p for p in parts if p]


def find_matching_angle(text: str, i: int) -> int:
    d = 0
    while i < len(text):
        if text[i] == "<": d += 1
        elif text[i] == ">":
            d -= 1
            if d == 0:
                return i
        i += 1
    raise RuntimeError("Unmatched < >")


# -------------------------------------------------------------------
# Reshape memory extraction
# -------------------------------------------------------------------

def find_decl_line_for_reshape(lines, i):
    j = i - 1
    while j >= 0 and RESHAPE_PRAGMA_RE.match(lines[j]):
        j -= 1
    return j


def collect_memories(lines):
    decls = OrderedDict()
    idx_map = {}
    for i, l in enumerate(lines):
        if RESHAPE_PRAGMA_RE.match(l):
            j = find_decl_line_for_reshape(lines, i)
            if j >= 0:
                c = lines[j].rstrip("\n")
                if ARRAY_DECL_RE.match(c):
                    decls.setdefault(c, True)
                    idx_map[j] = c
    return decls, idx_map


def decl_to_param(d):
    return d.rstrip(";").strip()


# -------------------------------------------------------------------
# Stream adapter detection
# -------------------------------------------------------------------

def find_adapter(text, cls):
    m = re.search(rf'\b{cls}\s*<', text)
    if not m:
        return None
    s = m.start()
    lt = text.find("<", m.end() - 1)
    gt = find_matching_angle(text, lt)
    m2 = re.match(r'\s*([A-Za-z_]\w*)\s*;', text[gt + 1:])
    obj = m2.group(1)
    inst_end = gt + 1 + m2.end()

    mrun = re.search(rf'\b{obj}\s*\.\s*run\s*<[^>]*>\s*\(', text[inst_end:])
    po = text.find("(", inst_end + mrun.end() - 1)
    d = 0
    i = po
    while True:
        if text[i] == "(":
            d += 1
        elif text[i] == ")":
            d -= 1
            if d == 0:
                pc = i
                break
        i += 1
    end = pc + 1 + re.match(r'\s*;', text[pc + 1:]).end()
    args = split_top_level_commas(text[po + 1:pc])
    return s, end, args


# -------------------------------------------------------------------
# Template parsing
# -------------------------------------------------------------------

def parse_nhwc(text, i):
    lt = text.find("<", i)
    gt = find_matching_angle(text, lt)
    args = split_top_level_commas(strip_cpp_line_comments(text[lt + 1:gt]))
    return dict(
        TOutput=args[3],
        HEIGHT=int(args[6]),
        WIDTH=int(args[7]),
        CH=int(args[8]),
        OUT_W_PAR=int(args[9]),
        OUT_CH_PAR=int(args[10]),
    )


def parse_streamtonhwc(text, i):
    lt = text.find("<", i)
    gt = find_matching_angle(text, lt)
    args = split_top_level_commas(strip_cpp_line_comments(text[lt + 1:gt]))
    return dict(
        TInput=args[1],
        ITER=int(args[5]),
        IN_W_PAR=int(args[10]),
        IN_CH_PAR=int(args[11]),
    )


# -------------------------------------------------------------------
# Signature utilities
# -------------------------------------------------------------------

def find_sig_span(text, fname):
    m = re.search(FUNC_START_RE_TEMPLATE.format(fname=fname), text)
    i = m.end() - 1
    d = 0
    while True:
        if text[i] == "(":
            d += 1
        elif text[i] == ")":
            d -= 1
            if d == 0:
                return m.start(), i + 1
        i += 1


def build_sig(fname, params):
    if not params:
        return f"void {fname}()"
    if len(params) == 1:
        return f"void {fname}({params[0]})"
    body = ",\n".join(f"    {p}" for p in params)
    return f"void {fname}(\n{body}\n)"


# -------------------------------------------------------------------
# Testbench
# -------------------------------------------------------------------

def generate_tb(fname, sig):
    ins = sig[sig.find("(") + 1:sig.rfind(")")].strip()
    params = split_top_level_commas(ins) if ins else []
    decls, args = [], []
    for p in params:
        m = re.search(r'\b(\w+)\b\s*(\[[^\]]*\].*)$', p)
        name = m.group(1)
        decls.append("    " + p + ";")
        args.append(name)
    call = f"    {fname}({', '.join(args)});"
    return f'''#include "ap_int.h"
#include "hls_stream.h"
#include <array>

extern {sig};

int main(int argc, char** argv)
{{
{chr(10).join(decls)}

{call}
    return 0;
}}
'''


# -------------------------------------------------------------------
# MAIN
# -------------------------------------------------------------------

def main():
    a = parse_args()
    lines = open(a.input_cpp).readlines()

    # Remove INTERFACE pragmas
    lines = [l for l in lines if not INTERFACE_PRAGMA_RE.match(l)]

    # Extract reshape memories
    mems, rm = collect_memories(lines)
    mem_params = [decl_to_param(d) for d in mems]
    lines = [l for i, l in enumerate(lines) if i not in rm]
    text = "".join(lines)

    params = []

    # NHWCToStream
    nhwc = find_adapter(text, "NHWCToStream")
    if nhwc:
        s, e, args = nhwc
        t = parse_nhwc(text, s)
        N = (t["HEIGHT"] * t["WIDTH"] * t["CH"]) // (t["OUT_CH_PAR"] * t["OUT_W_PAR"])
        params.append(f"std::array<std::array<{t['TOutput']}, {t['OUT_CH_PAR']}>, {t['OUT_W_PAR']}> in_data[{N}]")
        text = text[:s] + f"mm2s<{t['TOutput']}, {t['OUT_CH_PAR']}, {t['OUT_W_PAR']}, {N}>(in_data, {args[1]});" + text[e:]

    # StreamToNHWC
    stn = find_adapter(text, "StreamToNHWC")
    if stn:
        s, e, args = stn
        t = parse_streamtonhwc(text, s)
        params.append(f"std::array<std::array<{t['TInput']}, {t['IN_CH_PAR']}>, {t['IN_W_PAR']}> out_data[{t['ITER']}]")
        text = text[:s] + f"s2mm<{t['TInput']}, {t['IN_CH_PAR']}, {t['IN_W_PAR']}, {t['ITER']}>({args[0]}, out_data);" + text[e:]

    params = params + mem_params

    # Replace signature
    ss, se = find_sig_span(text, a.func)
    sig = build_sig(a.func, params)
    text = text[:ss] + sig + text[se:]

    # Inject include
    if 'stream_utils.hpp' not in text:
        text = '#include "utils/stream_utils.hpp"\n' + text

    open(a.output_cpp, "w").write(text)

    if a.tb:
        open(a.tb, "w").write(generate_tb(a.func, sig))


if __name__ == "__main__":
    main()
#!/usr/bin/env python3
"""
extract_move_reshape_mems.py

Usage:
  python extract_move_reshape_mems.py input.cpp output.cpp --func resnet8 [--mems memories.txt] [--tb testbench.cpp]

Pipeline:
1) Remove all '#pragma HLS INTERFACE ...' pragmas.
2) Extract memories associated with '#pragma HLS ARRAY_RESHAPE' and remove ONLY the
   corresponding array declaration lines from the file (keep reshape pragmas).
3) Replace NHWCToStream with mm2s and inject in_data into the interface.
4) Replace StreamToNHWC with s2mm and inject out_data into the interface.
5) Replace the top function signature entirely (NO old params kept).
6) Inject: #include "utils/stream_utils.hpp"
7) Optionally generate a testbench.
"""

import argparse
import re
from collections import OrderedDict
from typing import List, Tuple, Dict, Set, Optional

RESHAPE_PRAGMA_RE = re.compile(r'^\s*#\s*pragma\s+HLS\s+ARRAY_RESHAPE\b')
INTERFACE_PRAGMA_RE = re.compile(r'^\s*#\s*pragma\s+HLS\s+INTERFACE\b')

ARRAY_DECL_RE = re.compile(
    r"""^\s*
        (?:[A-Za-z_].*?)
        \b([A-Za-z_]\w*)\b
        \s*(\[[^\]]*\])\s*
        (?:\s*(\[[^\]]*\]\s*))*
        \s*;
        \s*$
        """,
    re.VERBOSE
)

FUNC_START_RE_TEMPLATE = r'\bvoid\s+{fname}\s*\('


def parse_args():
    p = argparse.ArgumentParser()
    p.add_argument("input_cpp")
    p.add_argument("output_cpp")
    p.add_argument("--func", required=True)
    p.add_argument("--mems", default=None)
    p.add_argument("--tb", default=None)
    return p.parse_args()


# -------------------------------------------------------------------
# Utility helpers
# -------------------------------------------------------------------

def strip_cpp_line_comments(s: str) -> str:
    out = []
    for l in s.splitlines():
        out.append(l.split("//", 1)[0] if "//" in l else l)
    return "\n".join(out)


def split_top_level_commas(s: str) -> List[str]:
    parts, cur = [], []
    da = dp = db = 0
    for c in s:
        if c == "<": da += 1
        elif c == ">": da -= 1
        elif c == "(": dp += 1
        elif c == ")": dp -= 1
        elif c == "[": db += 1
        elif c == "]": db -= 1

        if c == "," and da == dp == db == 0:
            parts.append("".join(cur).strip())
            cur = []
        else:
            cur.append(c)

    if cur:
        parts.append("".join(cur).strip())
    return [p for p in parts if p]


def find_matching_angle(text: str, i: int) -> int:
    d = 0
    while i < len(text):
        if text[i] == "<": d += 1
        elif text[i] == ">":
            d -= 1
            if d == 0:
                return i
        i += 1
    raise RuntimeError("Unmatched < >")


# -------------------------------------------------------------------
# Reshape memory extraction
# -------------------------------------------------------------------

def find_decl_line_for_reshape(lines, i):
    j = i - 1
    while j >= 0 and RESHAPE_PRAGMA_RE.match(lines[j]):
        j -= 1
    return j


def collect_memories(lines):
    decls = OrderedDict()
    idx_map = {}
    for i, l in enumerate(lines):
        if RESHAPE_PRAGMA_RE.match(l):
            j = find_decl_line_for_reshape(lines, i)
            if j >= 0:
                c = lines[j].rstrip("\n")
                if ARRAY_DECL_RE.match(c):
                    decls.setdefault(c, True)
                    idx_map[j] = c
    return decls, idx_map


def decl_to_param(d):
    return d.rstrip(";").strip()


# -------------------------------------------------------------------
# Stream adapter detection
# -------------------------------------------------------------------

def find_adapter(text, cls):
    m = re.search(rf'\b{cls}\s*<', text)
    if not m:
        return None
    s = m.start()
    lt = text.find("<", m.end() - 1)
    gt = find_matching_angle(text, lt)
    m2 = re.match(r'\s*([A-Za-z_]\w*)\s*;', text[gt + 1:])
    obj = m2.group(1)
    inst_end = gt + 1 + m2.end()

    mrun = re.search(rf'\b{obj}\s*\.\s*run\s*<[^>]*>\s*\(', text[inst_end:])
    po = text.find("(", inst_end + mrun.end() - 1)
    d = 0
    i = po
    while True:
        if text[i] == "(":
            d += 1
        elif text[i] == ")":
            d -= 1
            if d == 0:
                pc = i
                break
        i += 1
    end = pc + 1 + re.match(r'\s*;', text[pc + 1:]).end()
    args = split_top_level_commas(text[po + 1:pc])
    return s, end, args


# -------------------------------------------------------------------
# Template parsing
# -------------------------------------------------------------------

def parse_nhwc(text, i):
    lt = text.find("<", i)
    gt = find_matching_angle(text, lt)
    args = split_top_level_commas(strip_cpp_line_comments(text[lt + 1:gt]))
    return dict(
        TOutput=args[3],
        HEIGHT=int(args[6]),
        WIDTH=int(args[7]),
        CH=int(args[8]),
        OUT_W_PAR=int(args[9]),
        OUT_CH_PAR=int(args[10]),
    )


def parse_streamtonhwc(text, i):
    lt = text.find("<", i)
    gt = find_matching_angle(text, lt)
    args = split_top_level_commas(strip_cpp_line_comments(text[lt + 1:gt]))
    return dict(
        TInput=args[1],
        ITER=int(args[5]),
        IN_W_PAR=int(args[10]),
        IN_CH_PAR=int(args[11]),
    )


# -------------------------------------------------------------------
# Signature utilities
# -------------------------------------------------------------------

def find_sig_span(text, fname):
    m = re.search(FUNC_START_RE_TEMPLATE.format(fname=fname), text)
    i = m.end() - 1
    d = 0
    while True:
        if text[i] == "(":
            d += 1
        elif text[i] == ")":
            d -= 1
            if d == 0:
                return m.start(), i + 1
        i += 1


def build_sig(fname, params):
    if not params:
        return f"void {fname}()"
    if len(params) == 1:
        return f"void {fname}({params[0]})"
    body = ",\n".join(f"    {p}" for p in params)
    return f"void {fname}(\n{body}\n)"


# -------------------------------------------------------------------
# Testbench
# -------------------------------------------------------------------

def generate_tb(fname, sig):
    ins = sig[sig.find("(") + 1:sig.rfind(")")].strip()
    params = split_top_level_commas(ins) if ins else []
    decls, args = [], []
    for p in params:
        m = re.search(r'\b(\w+)\b\s*(\[[^\]]*\].*)$', p)
        name = m.group(1)
        decls.append("    " + p + ";")
        args.append(name)
    call = f"    {fname}({', '.join(args)});"
    return f'''#include "ap_int.h"
#include "hls_stream.h"
#include <array>

extern {sig};

int main(int argc, char** argv)
{{
{chr(10).join(decls)}

{call}
    return 0;
}}
'''


# -------------------------------------------------------------------
# MAIN
# -------------------------------------------------------------------

def main():
    a = parse_args()
    lines = open(a.input_cpp).readlines()

    # Remove INTERFACE pragmas
    lines = [l for l in lines if not INTERFACE_PRAGMA_RE.match(l)]

    # Extract reshape memories
    mems, rm = collect_memories(lines)
    mem_params = [decl_to_param(d) for d in mems]
    lines = [l for i, l in enumerate(lines) if i not in rm]
    text = "".join(lines)

    params = []

    # NHWCToStream
    nhwc = find_adapter(text, "NHWCToStream")
    if nhwc:
        s, e, args = nhwc
        t = parse_nhwc(text, s)
        N = (t["HEIGHT"] * t["WIDTH"] * t["CH"]) // (t["OUT_CH_PAR"] * t["OUT_W_PAR"])
        params.append(f"std::array<std::array<{t['TOutput']}, {t['OUT_CH_PAR']}>, {t['OUT_W_PAR']}> in_data[{N}]")
        text = text[:s] + f"mm2s<{t['TOutput']}, {t['OUT_CH_PAR']}, {t['OUT_W_PAR']}, {N}>(in_data, {args[1]});" + text[e:]

    # StreamToNHWC
    stn = find_adapter(text, "StreamToNHWC")
    if stn:
        s, e, args = stn
        t = parse_streamtonhwc(text, s)
        params.append(f"std::array<std::array<{t['TInput']}, {t['IN_CH_PAR']}>, {t['IN_W_PAR']}> out_data[{t['ITER']}]")
        text = text[:s] + f"s2mm<{t['TInput']}, {t['IN_CH_PAR']}, {t['IN_W_PAR']}, {t['ITER']}>({args[0]}, out_data);" + text[e:]

    params = params + mem_params

    # Replace signature
    ss, se = find_sig_span(text, a.func)
    sig = build_sig(a.func, params)
    text = text[:ss] + sig + text[se:]

    # Inject include
    if 'stream_utils.hpp' not in text:
        text = '#include "utils/stream_utils.hpp"\n' + text

    open(a.output_cpp, "w").write(text)

    if a.tb:
        open(a.tb, "w").write(generate_tb(a.func, sig))


if __name__ == "__main__":
    main()
