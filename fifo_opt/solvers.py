import enum
import random
from abc import ABC, abstractmethod
from enum import Enum
from functools import cached_property

import numpy as np
from scipy.optimize import Bounds, dual_annealing, minimize

from fifo_opt.opt_env import EvalResult, FIFOOptimizer


class ROUND_TYPE(enum.Enum):
    FLOOR = enum.auto()
    CEIL = enum.auto()
    FIX = enum.auto()
    TRUNC = enum.auto()
    ROUND = enum.auto()
    RINT = enum.auto()


def round(x: np.ndarray, round_type: ROUND_TYPE) -> np.ndarray:
    match round_type:
        case ROUND_TYPE.FLOOR:
            return np.floor(x)
        case ROUND_TYPE.CEIL:
            return np.ceil(x)
        case ROUND_TYPE.FIX:
            return np.fix(x)
        case ROUND_TYPE.TRUNC:
            return np.trunc(x)
        case ROUND_TYPE.ROUND:
            return np.round(x)
        case ROUND_TYPE.RINT:
            return np.rint(x)
        case _:
            raise ValueError(f"Unknown rounding type: {round_type}")


class RandomSearchOptimizer(FIFOOptimizer):
    def __init__(self, *args, n_samples: int = 100, seed: int = 7, **kwargs):
        super().__init__(*args, **kwargs)

        self.n_samples = n_samples
        self.seed = seed
        self.r = random.Random(seed)

    def solve(self) -> list[EvalResult] | None:
        fifos_dse_space = {}
        for fifo in self.fifos:
            fifo_id = fifo.id
            fifo_depths = self.trace_base.compiled.get_fifo_design_space(
                [fifo_id], fifo.width
            )
            fifos_dse_space[fifo_id] = fifo_depths

        sampled_configs = []
        for _ in range(self.n_samples):
            sample: dict[int, int] = {}
            for fifo_id, fifo_depths in fifos_dse_space.items():
                sample[fifo_id] = self.r.choice(fifo_depths)
            sampled_configs.append(sample)

        results = []
        for sample_config in sampled_configs:
            result = self.eval_solution_single(sample_config)
            results.append(result)

        return results


class GAOptimizer(FIFOOptimizer):
    def solve(self) -> dict | None:
        raise NotImplementedError


class PSOptimizer(FIFOOptimizer):
    def solve(self) -> dict | None:
        raise NotImplementedError


class BayesianOptimizer(FIFOOptimizer):
    def solve(self) -> dict | None:
        raise NotImplementedError


class SimulatedAnnealingOptimizer(FIFOOptimizer):
    # def __init__(self, name: str, round_type: ROUND_TYPE = ROUND_TYPE.RINT):
    def __init__(self, *args, round_type: ROUND_TYPE = ROUND_TYPE.RINT, **kwargs):
        super().__init__(*args, **kwargs)
        self.round_type = round_type

    def solve(self) -> dict | None:
        n = self.num_fifos

        # def objective_function(x: np.ndarray) -> float:
        #     x = round(x, self.round_type)
        #     y = eval_solution(x)
        #     return y

        # bounds = Bounds(
        #     lb=np.full_like((n,), self.min_fifo_size),
        #     ub=np.full_like((n,), np.inf),
        # )
        # result = dual_annealing(
        #     objective_function,
        #     bounds=bounds,
        #     maxiter=1000,
        #     local_search_options={"method": "L-BFGS-B"},
        # )

        # TODO: post-process the result to get a list solutions
        # return result.x

        raise NotImplementedError


class HuristicOptimizer(FIFOOptimizer):
    def solve(self) -> dict | None:
        raise NotImplementedError
