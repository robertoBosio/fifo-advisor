import enum
from abc import ABC, abstractmethod
from enum import Enum
from functools import cached_property

import numpy as np
from scipy.optimize import Bounds, dual_annealing, minimize

from fifo_opt.opt_env import FIFOOptimizer


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




class GAOptimizer(FIFOOptimizer):
    def solve(self, fifo_metadata: dict, target_latency: int) -> list:
        raise NotImplementedError


class PSOptimizer(FIFOOptimizer):
    def solve(self, fifo_metadata: dict, target_latency: int) -> list:
        raise NotImplementedError


class BayesianOptimizer(FIFOOptimizer):
    def solve(self, fifo_metadata: dict, target_latency: int) -> list:
        raise NotImplementedError


class SimulatedAnnealingOptimizer(FIFOOptimizer):
    def __init__(self, name: str, round_type: ROUND_TYPE = ROUND_TYPE.RINT):
        super().__init__(name)
        self.round_type = round_type 

    def solve(self, fifo_metadata: dict, target_latency: int) -> list:
        n = fifo_metadata["n_fifos"]

        def objective_function(x: np.ndarray) -> float:
            x = round(x, self.round_type)
            y = eval_solution(x)
            return y

        bounds = Bounds(
            lb=np.full_like((n,), self.min_fifo_size),
            ub=np.full_like((n,), np.inf),
        )
        result = dual_annealing(
            objective_function,
            bounds=bounds,
            maxiter=1000,
            local_search_options={"method": "L-BFGS-B"},
        )

        # TODO: post-process the result to get a list solutions
        return result.x


# need a better way to accept and pass on scpy.optimize.minimize options
class ScipyMinimizeOptimizer(FIFOOptimizer):
    def __init__(
        self,
        name: str,
        scipy_optimizer_method: str = "L-BFGS-B",
        scipy_optimizer_options: dict | None = None,
        round_type: ROUND_TYPE = ROUND_TYPE.RINT,
    ):
        super().__init__(name)
        self.round_type = round_type

        self.scipy_optimizer_method = scipy_optimizer_method
        self.scipy_optimizer_options = scipy_optimizer_options

    def solve(self, fifo_metadata: dict, target_latency: int) -> list:
        # use scipy.optimize.minimize
        n = fifo_metadata["n_fifos"]

        def objective_function(x: np.ndarray) -> float:
            x = round(x, self.round_type)
            y = eval_solution(x)
            return y

        bounds = Bounds(
            lb=np.full_like((n,), self.min_fifo_size),
            ub=np.full_like((n,), np.inf),
        )

        result = minimize(
            objective_function,
            x0=np.full_like((n,), self.min_fifo_size),
            bounds=bounds,
            method=self.scipy_optimizer_method,
            options=self.scipy_optimizer_options,
        )

        x_sol = result.x
        return x_sol


# There will probably be many "heuristic" optimizers.
# For example, we could have a "greedy" optimizer
# or a halfing + binary search optimizer.
class HuristicOptimizer(FIFOOptimizer):
    def solve(self, fifo_metadata: dict, target_latency: int) -> list:
        raise NotImplementedError


class RandomOptimizer(FIFOOptimizer):
    def __init__(self, name: str, n_samples: int, upper_bound: int):
        super().__init__(name)
        self.n_samples = n_samples
        # TODO need a principled way to pick an upper bound for the sampled values
        # Are there some wasy we can do it by looking at the design?
        self.upper_bound = upper_bound

    def solve(self, fifo_metadata: dict, target_latency: int) -> list:
        n = fifo_metadata["n_fifos"]

        x = np.random.randint(
            low=self.min_fifo_size,
            high=self.upper_bound,
            size=(self.n_samples, n),
        )
        y = eval_solution(x)
        sorted_indices = np.argsort(y)
        x_sorted = x[sorted_indices]
        
        
        raise NotImplementedError


# class FIFOOptimizerRuntime:
#     def __init__(
#         self,
#         initial_fifo_data: list,
#         optimizers: list[FIFOOptimizer],
#         min_fifo_size: int = 2,
#     ):
#         self.initial_fifo_data = initial_fifo_data
#         self.optimizers = optimizers
#         self.min_fifo_size = min_fifo_size

#     @cached_property
#     def fifo_ids(self):
#         pass

#     @cached_property
#     def n_fifo(self):
#         return len(self.fifo_ids)

#     @cached_property
#     def fifo_metadata(self):
#         return {
#             "n_fifos": self.n_fifo,
#             "fifo_ids": self.fifo_ids,
#             "min_fifo_size": self.min_fifo_size,
#         }
    

#     def compute_unconstrained_latency(self) -> float:
#         pass

#     def run_latency_minimal(self):
#         solutions: {str: list} = {}
#         for optimizer in self.optimizers:
#             solver_solutions = optimizer.solve(self.fifo_metadata, 0.0)
#             solutions[optimizer.name] = solver_solutions
#         return solutions

#     def run_latency_frontier(self, n_points: int):
#         # crate a log scale of latency targets from the minimal found

#         # min_latency = self.compute_unconstrained_latency()
#         min_latency = 1e-6  # TODO: switch to compute_unconstrained_latency when ready
#         max_latency = self.compute_latency(self.min_fifo_size)

#         latency_targets = np.logspace(
#             start=np.log10(min_latency),
#             stop=np.log10(max_latency),
#             base=10,
#             num=n_points,
#             endpoint=True,
#         )
