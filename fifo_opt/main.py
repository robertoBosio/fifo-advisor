import argparse
from pathlib import Path

from fifo_opt.solvers import RandomSearchOptimizer


def main(args):
    solution_dir: Path = args.solution_dir

    # 1. Load the design into the lihgtningsim model for exploration
    # build lightningsim trace
    # parse trace into lightningsim model
    # extract design fifos and initial fifo depths

    # 2. Run optimization algorithms to find FIFO depth soltuions

    # 3. Provide the user with the results via logging, files, or a web interface.

    optimizer = RandomSearchOptimizer(solution_dir)
    optimizer.solve()


if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        prog="fifo_opt",
        description=(
            "A tool for optimizing FIFOs depths in a high-level synthesis design using"
            " different optimization algorithms and fast co-simulation."
        ),
        usage="python fifo_opt.py solution_dir",
    )
    parser.add_argument("solution_dir", type=Path)
    args = parser.parse_args()
    main(args)
