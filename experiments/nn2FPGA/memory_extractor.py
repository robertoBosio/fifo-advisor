#!/usr/bin/env python3
"""
extract_above_reshape.py

Usage:
  python extract_above_reshape.py input.cpp output.txt

Behavior:
- For every line containing '#pragma HLS ARRAY_RESHAPE', look at the previous
  lines going upward until the first line that is NOT a reshape pragma.
- If that line looks like a single-line array declaration (has [] and ends
  with ';'), capture it.
- Write each unique captured declaration to output.txt in the order found.
"""

import sys
import re
from collections import OrderedDict

RESHAPE_PRAGMA_RE = re.compile(r'^\s*#\s*pragma\s+HLS\s+ARRAY_RESHAPE\b')
# Heuristic: single-line array declaration: type ... name[...][...];
ARRAY_DECL_RE = re.compile(
    r"""^\s*                     # leading space
        (?:[A-Za-z_].*?)         # some type-ish text before the name
        \b([A-Za-z_]\w*)\b       # variable name (group 1)
        \s*(\[[^\]]*\])\s*       # at least one []
        (?:\s*(\[[^\]]*\]\s*))*  # optionally more []
        \s*;                     # semicolon terminator
        """,
    re.VERBOSE
)

def main():
    if len(sys.argv) != 3:
        print("Usage: python extract_above_reshape.py <input.cpp> <output.txt>")
        sys.exit(2)

    inp, outp = sys.argv[1], sys.argv[2]

    with open(inp, "r", encoding="utf-8") as f:
        lines = f.readlines()

    captured = OrderedDict()  # decl_line -> True (preserve order, dedup)

    n = len(lines)
    for i, line in enumerate(lines):
        if not RESHAPE_PRAGMA_RE.match(line):
            continue

        # Walk upward to find the first non-reshape line
        j = i - 1
        while j >= 0 and RESHAPE_PRAGMA_RE.match(lines[j]):
            j -= 1

        if j < 0:
            continue

        candidate = lines[j].rstrip("\n")

        # Quick sanity: must end with ';' and contain at least one '[]'
        if ";" in candidate and "[" in candidate and "]" in candidate:
            if ARRAY_DECL_RE.match(candidate):
                # Keep the exact line as-is
                if candidate not in captured:
                    captured[candidate] = True

    with open(outp, "w", encoding="utf-8") as f:
        for decl in captured.keys():
            f.write(decl + "\n")

if __name__ == "__main__":
    main()
