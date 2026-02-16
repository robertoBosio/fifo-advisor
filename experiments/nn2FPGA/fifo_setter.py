#!/usr/bin/env python3
import csv
import re
import sys
import json
from pathlib import Path

PRAGMA_RE = re.compile(
    r"""
    ^(?P<prefix>\s*\#\s*pragma\s+HLS\s+STREAM\s+variable=)  # pragma + prefix up to variable=
    (?P<var>[A-Za-z_][A-Za-z0-9_]*)                         # variable base name
    (?:\[(?P<idx>\d+)\])?                                   # optional [index]
    (?P<mid>\s+depth=)                                      # space + depth=
    (?P<depth>\d+)                                          # current depth number
    (?P<suffix>.*)$                                         # rest of line
    """,
    re.VERBOSE,
)

TRAILING_DIGITS_RE = re.compile(r"^(?P<base>.*?)(?P<num>\d+)$")

def normalize_csv_key(key: str):
    key = key.strip()
    if not key:
        return None
    m = re.match(r"^(.*)_(\d+)$", key)        # name_8 -> (name, 8)
    if m:
        return (m.group(1), int(m.group(2)))
    m = TRAILING_DIGITS_RE.match(key)         # name7  -> (name, 0)
    if m:
        return (m.group("base"), 0)
    return (key, 0)                           # name   -> (name, 0)

def load_depth_map_csv(csv_path: Path):
    mapping = {}
    with csv_path.open(newline="") as f:
        reader = csv.reader(f)
        for row in reader:
            if not row or len(row) < 2:
                continue
            key, val = row[0].strip(), row[1].strip()
            norm = normalize_csv_key(key)
            if not norm:
                continue
            try:
                mapping[norm] = int(val)
            except ValueError:
                pass
    return mapping

def load_depth_map_json(json_path: Path):
    mapping = {}
    with json_path.open() as f:
        data = json.load(f)
        fifo_data = data.get("evaluations", {}).get("fifo_sizes", {})
        for key, val in fifo_data.items():
            norm = normalize_csv_key(key)
            if not norm:
                continue
            try:
                mapping[norm] = int(val)
            except ValueError:
                pass
    return mapping

def main():
    if len(sys.argv) != 4:
        print("Usage: python fifo_setter.py <input.cpp> <depths.csv/depths.json> <output.cpp>")
        sys.exit(1)

    in_path  = Path(sys.argv[1])
    depth_map_path = Path(sys.argv[2])
    out_path = Path(sys.argv[3])

    if depth_map_path.suffix.lower() == ".json":
        depth_map = load_depth_map_json(depth_map_path)
    else:
        depth_map = load_depth_map_csv(depth_map_path)

    replaced = 0
    unmatched = 0
    out_lines = []

    for line in in_path.read_text(encoding="utf-8", errors="ignore").splitlines(keepends=False):
        m = PRAGMA_RE.match(line)
        if not m:
            out_lines.append(line)
            continue

        var_base = m.group("var")
        idx_str  = m.group("idx")
        idx      = int(idx_str) if idx_str is not None else 0
        key      = (var_base, idx)

        if key in depth_map:
            new_depth = str(depth_map[key])
            new_line = (
                f"{m.group('prefix')}{var_base}"
                + (f"[{idx}]" if idx_str is not None else "")
                + f"{m.group('mid')}{new_depth}{m.group('suffix')}"
            )
            out_lines.append(new_line)
            replaced += 1
        else:
            out_lines.append(line)
            unmatched += 1

    out_path.write_text("\n".join(out_lines) + "\n", encoding="utf-8")
    print(f"Updated pragmas: {replaced}", file=sys.stderr)
    if unmatched:
        print(f"Pragmas without match (left unchanged): {unmatched}", file=sys.stderr)

if __name__ == "__main__":
    main()
