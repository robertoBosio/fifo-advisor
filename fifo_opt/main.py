import argparse
from pathlib import Path

from fifo_opt.opt_env import LSEnv
from fifo_opt.solvers import RandomSearchOptimizer


def main(args):
    solution_dir: Path = args.solution_dir
    sim_env = LSEnv(solution_dir)
    optimizer = RandomSearchOptimizer(sim_env)
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
