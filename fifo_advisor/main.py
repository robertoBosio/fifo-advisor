from __future__ import annotations

import argparse
import json
from dataclasses import dataclass
from pathlib import Path
from typing import Any

from fifo_advisor.opt_env import EvalResult, FIFOOptimizer, LSEnv
from fifo_advisor.solvers import (
    ROUND_TYPE,
    DiscreteSimulatedAnnealingOptimizer,
    GroupedDiscreteSimulatedAnnealingOptimizer,
    GroupRandomSearchOptimizer,
    HeuristicOptimizer,
    RandomSearchOptimizer,
)


@dataclass(frozen=True)
class SolverSpec:
    cls: type[FIFOOptimizer]
    allowed_kwargs: set[str]


SOLVER_SPECS: dict[str, SolverSpec] = {
    "random": SolverSpec(
        cls=RandomSearchOptimizer,
        allowed_kwargs={"n_samples", "seed"},
    ),
    "group-random": SolverSpec(
        cls=GroupRandomSearchOptimizer,
        allowed_kwargs={"n_samples", "seed"},
    ),
    "heuristic": SolverSpec(
        cls=HeuristicOptimizer,
        allowed_kwargs=set(),
    ),
    "sa": SolverSpec(
        cls=DiscreteSimulatedAnnealingOptimizer,
        allowed_kwargs={
            "maxfun",
            "n_scaling_factors",
            "round_type",
            "init_with_largest",
        },
    ),
    "group-sa": SolverSpec(
        cls=GroupedDiscreteSimulatedAnnealingOptimizer,
        allowed_kwargs={
            "maxfun",
            "n_scaling_factors",
            "round_type",
            "init_with_largest",
        },
    ),
}

ROUND_TYPE_CHOICES = {
    name.lower(): member for name, member in ROUND_TYPE.__members__.items()
}


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        prog="fifo-advisor",
        description=(
            "A tool for optimizing FIFO depths in a high-level synthesis design using"
            " different optimization algorithms and fast co-simulation."
        ),
        usage="fifo-advisor <solution_dir> [options]",
        allow_abbrev=False,
    )
    parser.add_argument("solution_dir", type=Path)
    parser.add_argument(
        "--solver",
        choices=list(SOLVER_SPECS.keys()),
        default="random",
        help="Optimization strategy to run (default: random)",
    )
    parser.add_argument(
        "--n-samples",
        type=int,
        default=None,
        help="Sample count for random-based solvers.",
    )
    parser.add_argument(
        "--seed",
        type=int,
        default=None,
        help="Random seed for stochastic solvers.",
    )
    parser.add_argument(
        "--maxfun",
        type=int,
        default=None,
        help="Evaluation budget for simulated annealing solvers.",
    )
    parser.add_argument(
        "--n-scaling-factors",
        type=int,
        default=None,
        help="Number of dual objective scaling factors for simulated annealing solvers.",
    )
    parser.add_argument(
        "--round-type",
        choices=list(ROUND_TYPE_CHOICES.keys()),
        default=None,
        help="Rounding mode for simulated annealing solvers.",
    )
    parser.add_argument(
        "--init-with-largest",
        action="store_true",
        help="Start simulated annealing from the largest FIFO depths.",
    )
    parser.add_argument(
        "--output",
        type=Path,
        default=Path("fifo_advisor_results.json"),
        help="Write optimizer evaluations to this JSON file (default: fifo_advisor_results.json).",
    )
    return parser


def collect_solver_kwargs(
    args: argparse.Namespace,
) -> tuple[type[FIFOOptimizer], dict[str, Any]]:
    solver_key = args.solver
    solver_spec = SOLVER_SPECS[solver_key]

    provided_values: dict[str, Any] = {
        "n_samples": args.n_samples,
        "seed": args.seed,
        "maxfun": args.maxfun,
        "n_scaling_factors": args.n_scaling_factors,
        "round_type": args.round_type,
    }

    solver_kwargs: dict[str, Any] = {}
    for param, value in provided_values.items():
        if value is None:
            continue
        if param not in solver_spec.allowed_kwargs:
            raise ValueError(
                f"Parameter '{param}' is not supported by solver '{solver_key}'."
            )
        if param == "round_type":
            solver_kwargs[param] = ROUND_TYPE_CHOICES[value]
        else:
            solver_kwargs[param] = value

    if args.init_with_largest:
        if "init_with_largest" not in solver_spec.allowed_kwargs:
            raise ValueError(
                f"Parameter 'init_with_largest' is not supported by solver '{solver_key}'."
            )
        solver_kwargs["init_with_largest"] = True

    return solver_spec.cls, solver_kwargs


def main(args: argparse.Namespace) -> None:
    solution_dir: Path = args.solution_dir
    sim_env = LSEnv(solution_dir)
    solver_cls, solver_kwargs = collect_solver_kwargs(args)
    optimizer = solver_cls(sim_env, **solver_kwargs)
    results = optimizer.solve()
    serialized = serialize_eval_results(results)
    emit_results(serialized, args.output)


def serialize_eval_results(results: list[EvalResult]) -> list[dict[str, Any]]:
    payload: list[dict[str, Any]] = []
    for result in results:
        payload.append(
            {
                "fifo_sizes": {
                    str(fifo_id): depth for fifo_id, depth in result.fifo_sizes.items()
                },
                "deadlock": result.deadlock,
                "latency": result.latency,
                "bram_usage_total": result.bram_usage_total,
                "timestamp": result.timestamp,
            }
        )
    return payload


def emit_results(payload: list[dict[str, Any]], output_path: Path) -> None:
    json_blob = json.dumps(payload, indent=2)
    output_path.parent.mkdir(parents=True, exist_ok=True)
    output_path.write_text(json_blob)


def cli() -> None:
    parser = build_parser()
    args = parser.parse_args()
    try:
        main(args)
    except ValueError as exc:
        parser.error(str(exc))


if __name__ == "__main__":
    cli()
