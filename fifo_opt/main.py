import argparse
from pathlib import Path

from fifo_opt.opt_env import LSEnv
from fifo_opt.solvers import RandomSearchOptimizer


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        prog="fifo_opt",
        description=(
            "A tool for optimizing FIFOs depths in a high-level synthesis design using"
            " different optimization algorithms and fast co-simulation."
        ),
        usage="fifo_opt <solution_dir>",
    )
    parser.add_argument("solution_dir", type=Path)
    return parser


def main(args: argparse.Namespace) -> None:
    solution_dir: Path = args.solution_dir
    sim_env = LSEnv(solution_dir)
    optimizer = RandomSearchOptimizer(sim_env)
    optimizer.solve()


def cli() -> None:
    parser = build_parser()
    args = parser.parse_args()
    main(args)


if __name__ == "__main__":
    cli()
