import enum
import itertools
import random
import time
from collections import defaultdict
from copy import deepcopy
from typing import TypeAlias, Union

import numpy as np
from lightningsim.trace_file import ResolvedStream
from pymoo.algorithms.moo.nsga2 import NSGA2
from pymoo.core.callback import Callback
from pymoo.core.problem import Problem
from pymoo.operators.crossover.sbx import SBX
from pymoo.operators.mutation.pm import PM
from pymoo.operators.repair.rounding import RoundingRepair
from pymoo.operators.sampling.rnd import IntegerRandomSampling
from pymoo.optimize import minimize as minimize_pymoo
from scipy.optimize import Bounds, dual_annealing
from scipy.optimize._optimize import OptimizeResult

from fifo_opt.opt_env import (
    EvalResult,
    FIFOOptimizer,
    LSEnv,
    is_pareto_efficient_simple,
)


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


def compute_dual_obj_scaling_factors(N_points: int) -> np.ndarray:
    first_row = np.linspace(0, 1, N_points, endpoint=True)
    second_row = first_row[::-1]
    return np.vstack((first_row, second_row)).T


def count_configs(sim_env) -> int:
    fifos_dse_space = {}
    for fifo in sim_env.fifos:
        fifo_id = fifo.id
        fifo_depths = sim_env.trace_base.compiled.get_fifo_design_space(
            [fifo_id], fifo.width
        )
        fifos_dse_space[fifo_id] = fifo_depths

    design_space_size = 1
    for fifo_id, fifo_depths in fifos_dse_space.items():
        design_space_size *= len(fifo_depths)
    return design_space_size


def count_configs_grouped(sim_env) -> int:
    fifo_groups = defaultdict(list)
    for fifo in sim_env.fifos:
        fifo_groups[fifo.get_display_name()].append(fifo)

    fifo_groups_depths = {}
    for fifo_group, fifos in fifo_groups.items():
        fifo_groups_depths[fifo_group] = (
            sim_env.trace_base.compiled.get_fifo_design_space(
                [fifo.id for fifo in fifos], fifos[0].width
            )
        )

    design_space_size = 1
    for fifo_id, fifo_depths in fifo_groups_depths.items():
        design_space_size *= len(fifo_depths)
    return design_space_size


class RandomSearchOptimizer(FIFOOptimizer):
    def __init__(self, sim_env: LSEnv, n_samples: int = 100, seed: int = 7):
        super().__init__(sim_env)

        self.n_samples = n_samples
        self.seed = seed
        self.r = random.Random(seed)

    def solve(self) -> list[EvalResult]:
        fifos_dse_space = {}
        for fifo in self.sim_env.fifos:
            fifo_id = fifo.id
            fifo_depths = self.sim_env.trace_base.compiled.get_fifo_design_space(
                [fifo_id], fifo.width
            )
            fifos_dse_space[fifo_id] = fifo_depths
        # print(fifos_dse_space)

        sampled_configs = []
        for _ in range(self.n_samples):
            sample: dict[int, int] = {}
            for fifo_id, fifo_depths in fifos_dse_space.items():
                sample[fifo_id] = self.r.choice(fifo_depths)
            sampled_configs.append(sample)

        results: list[EvalResult] = self.sim_env.eval_solution_parallel(sampled_configs)

        return results


class GroupRandomSearchOptimizer(FIFOOptimizer):
    def __init__(
        self,
        sim_env: LSEnv,
        n_samples: int = 100,
        seed: int = 7,
    ):
        super().__init__(sim_env)

        self.n_samples = n_samples
        self.seed = seed
        self.r = random.Random(seed)

    # def solve(self) -> list[EvalResult]:
    def solve(self) -> list[EvalResult]:
        fifo_groups = defaultdict(list)
        for fifo in self.sim_env.fifos:
            fifo_groups[fifo.get_display_name()].append(fifo)

        fifo_groups_depths = {}
        for fifo_group, fifos in fifo_groups.items():
            fifo_groups_depths[fifo_group] = (
                self.sim_env.trace_base.compiled.get_fifo_design_space(
                    [fifo.id for fifo in fifos], fifos[0].width
                )
            )

        design_space_size = 1
        for fifo_id, fifo_depths in fifo_groups_depths.items():
            design_space_size *= len(fifo_depths)
        # print("NAME: ", self.sim_env.vitis_hls_solution_dir.parent.name)
        # print("SIZE: ", design_space_size)
        # print(
        #     f"NAME: {self.sim_env.vitis_hls_solution_dir.parent.name}, SIZE: {design_space_size}"
        # )

        sampled_configs = []
        for _ in range(self.n_samples):
            sample: dict[int, int] = {}
            for fifo_group, fifo_depths in fifo_groups_depths.items():
                group_depths = self.r.choice(fifo_depths)
                for fifo in fifo_groups[fifo_group]:
                    sample[fifo.id] = group_depths
            sampled_configs.append(sample)

        results = self.sim_env.eval_solution_parallel(sampled_configs)

        return results


class GroupExhaustiveOptimizer(FIFOOptimizer):
    def __init__(self, sim_env: LSEnv, size_limit: int = 10_000, seed: int = 7):
        super().__init__(sim_env)

        self.size_limit = size_limit
        self.seed = seed
        self.r = random.Random(seed)

    def solve(self) -> list[EvalResult]:
        fifo_groups = defaultdict(list)
        for fifo in self.sim_env.fifos:
            fifo_groups[fifo.get_display_name()].append(fifo)

        fifo_groups_depths = {}
        for fifo_group, fifos in fifo_groups.items():
            fifo_groups_depths[fifo_group] = (
                self.sim_env.trace_base.compiled.get_fifo_design_space(
                    [fifo.id for fifo in fifos], fifos[0].width
                )
            )

        design_space_size = 1
        for fifo_group, fifo_depths in fifo_groups_depths.items():
            design_space_size *= len(fifo_depths)

        if design_space_size > self.size_limit:
            raise ValueError(
                f"Design space size {design_space_size} exceeds limit {self.size_limit}. Use a larger size limit or different optimizer."
            )

        fifo_groups_keys = list(fifo_groups_depths.keys())
        fifo_groups_values = list(fifo_groups_depths.values())

        combos = itertools.product(
            *fifo_groups_values,
        )

        samples = []
        for combo in combos:
            sample: dict[int, int] = {}
            for fifo_group, fifo_depths in zip(fifo_groups_keys, combo):
                for fifo in fifo_groups[fifo_group]:
                    sample[fifo.id] = fifo_depths
            samples.append(sample)

        assert len(samples) == design_space_size, (
            "mismatch in computed design space size and samples generated size"
        )

        results = self.sim_env.eval_solution_parallel(samples)

        return results


class FIFOOptProblemInt(Problem):
    def __init__(
        self,
        fifo_optmizer_obj: FIFOOptimizer,
        n_fifos: int,
        fifo_ids: list[int],
        fifo_upper_bounds: dict[int, int],
    ):
        self.fifo_optmizer_obj = fifo_optmizer_obj
        self.n_fifos = n_fifos
        self.fifo_ids = fifo_ids
        self.fifo_upper_bounds = fifo_upper_bounds
        assert len(set(fifo_upper_bounds.keys())) == n_fifos, (
            "Must have a fifo upper bound for each fifo"
        )

        fifo_upper_bounds_ordered = [fifo_upper_bounds[fifo_id] for fifo_id in fifo_ids]

        super().__init__(
            n_var=self.n_fifos,
            n_obj=2,
            n_ieq_constr=1,
            xl=2 * np.ones(self.n_fifos),
            xu=np.array(fifo_upper_bounds_ordered),
            vtype=int,
        )

    def _evaluate(self, x, out, *args, **kwargs):
        fifo_sizes = []
        for solution in x:
            fifo_sizes.append(
                {fifo_id: size for fifo_id, size in zip(self.fifo_ids, solution)}
            )
        results = self.fifo_optmizer_obj.sim_env.eval_solution_parallel(fifo_sizes)
        F = np.zeros((len(results), 2))
        G = np.zeros((len(results), 1))
        for i, result in enumerate(results):
            if result.deadlock:
                F[i] = [np.inf, np.inf]
                G[i][0] = 1
            else:
                F[i] = [result.latency, result.bram_usage_total]
                G[i][0] = -1
        out["F"] = F
        out["G"] = G


class ResultsHistoryTracker(Callback):
    def __init__(self, fifo_optmizer_obj: FIFOOptimizer, fifo_ids: list[int]):
        super().__init__()
        self.fifo_optmizer_obj = fifo_optmizer_obj
        self.fifo_ids = fifo_ids
        self.all_results: list[EvalResult] = []

    def notify(self, algorithm):
        X = algorithm.pop.get("X")
        fifo_configs = []
        for x in X:
            fifo_sizes = {fifo_id: size for fifo_id, size in zip(self.fifo_ids, x)}
            fifo_configs.append(fifo_sizes)
        results = self.fifo_optmizer_obj.sim_env.eval_solution_parallel(fifo_configs)
        self.all_results.extend(results)


class GAOptimizer(FIFOOptimizer):
    def __init__(
        self,
        sim_env: LSEnv,
        seed: int = 7,
        n_gen: int = 10,
        pop_size: int = 100,
    ):
        super().__init__(
            sim_env,
        )

        self.seed = seed
        self.n_gen = n_gen
        self.pop_size = pop_size

        # check that all values in fifo_sizes_base are not none
        if any(
            fifo_size is None for fifo_size in self.sim_env.fifo_sizes_base.values()
        ):
            raise ValueError(
                "All fifo sizes must have a default value to have some kind of upper bound for the optimization."
            )

        self.fifo_ids = [fifo.id for fifo in self.sim_env.fifos]

        self.problem = FIFOOptProblemInt(
            self,
            n_fifos=self.sim_env.num_fifos,
            fifo_ids=self.fifo_ids,
            fifo_upper_bounds=self.sim_env.fifo_sizes_base,
        )

        self.algorithm = NSGA2(
            pop_size=self.pop_size,
            eliminate_duplicates=True,
            sampling=IntegerRandomSampling(),
            crossover=SBX(prob=0.5, eta=15, vtype=float, repair=RoundingRepair()),
            mutation=PM(prob=0.5, eta=20, vtype=float, repair=RoundingRepair()),
        )

    def solve(self) -> list[EvalResult]:
        results_history_tracker = ResultsHistoryTracker(self, self.fifo_ids)

        _res = minimize_pymoo(
            self.problem,
            self.algorithm,
            termination=("n_gen", self.n_gen),
            seed=self.seed,
            save_history=False,
            callback=results_history_tracker,
            verbose=True,
        )

        return results_history_tracker.all_results


class PSOptimizer(FIFOOptimizer):
    def solve(self) -> list[EvalResult]:
        raise NotImplementedError


class BayesianOptimizer(FIFOOptimizer):
    def solve(self) -> list[EvalResult]:
        raise NotImplementedError


class SimulatedAnnealingOptimizer(FIFOOptimizer):
    def __init__(
        self,
        sim_env: LSEnv,
        maxfun: int = 100,
        round_type: ROUND_TYPE = ROUND_TYPE.RINT,
        init_pool: list[EvalResult] | None = None,
    ):
        super().__init__(sim_env)
        self.maxfun = maxfun
        self.round_type = round_type
        self.init_pool = init_pool

        self.fifo_ids = [fifo.id for fifo in self.sim_env.fifos]
        self.n_scaling_factors = 8
        self.dual_objective_scaling_factors = compute_dual_obj_scaling_factors(
            self.n_scaling_factors
        )

    def solve(self) -> list[EvalResult]:
        results = []

        results_all = []

        sampled_x0: list[list[int]] | list[None] = []
        if self.init_pool is not None:
            sampled_eval_results = random.choices(
                self.init_pool, k=self.n_scaling_factors
            )
            sampled_configs = [r.fifo_sizes for r in sampled_eval_results]
            sampled_x0 = []
            for sample_config in sampled_configs:
                x0 = [sample_config[fifo_id] for fifo_id in self.fifo_ids]
                sampled_x0.append(x0)
        else:
            sampled_x0 = [None for _ in range(self.n_scaling_factors)]

        for idx in range(self.n_scaling_factors):
            scaling_factor_latency = self.dual_objective_scaling_factors[idx, 0]
            scaling_factor_bram = self.dual_objective_scaling_factors[idx, 1]

            def objective_function(x: np.ndarray) -> float:
                x = round(x, self.round_type).astype(int)
                sample = dict(zip(self.fifo_ids, x))  # Directly construct dictionary

                y = self.sim_env.eval_solution_single(sample)
                results_all.append(y)

                if y.deadlock:
                    return np.inf

                return (
                    scaling_factor_latency * y.latency
                    + scaling_factor_bram * y.bram_usage_total
                )

            bounds = Bounds(
                lb=np.full_like((self.sim_env.num_fifos,), self.sim_env.min_fifo_size),  # type: ignore
                ub=np.array(
                    [self.sim_env.fifo_sizes_base[fifo_id] for fifo_id in self.fifo_ids]  # type: ignore
                ),
            )

            result = dual_annealing(
                objective_function,
                bounds=bounds,
                maxfun=self.maxfun,
                no_local_search=True,
                rng=7,
                x0=sampled_x0[idx],  # type: ignore
            )
            x_rounded = round(result.x, self.round_type)
            x_python = x_rounded.tolist()
            x_python_int = [int(x) for x in x_python]

            sol_sample = {
                fifo_id: size for fifo_id, size in zip(self.fifo_ids, x_python_int)
            }
            sol_eval_results = self.sim_env.eval_solution_single(sol_sample)
            results.append(sol_eval_results)

        return results_all


class DiscreteSimulatedAnnealingOptimizer(FIFOOptimizer):
    def __init__(
        self,
        sim_env: LSEnv,
        maxfun: int = 100,
        n_scaling_factors: int = 8,
        round_type: ROUND_TYPE = ROUND_TYPE.RINT,
        init_with_largest: bool = False,
    ):
        super().__init__(sim_env)
        self.maxfun = maxfun
        self.round_type = round_type
        self.init_with_largest = init_with_largest

        self.fifo_ids = [fifo.id for fifo in self.sim_env.fifos]
        self.n_scaling_factors = n_scaling_factors
        self.dual_objective_scaling_factors = compute_dual_obj_scaling_factors(
            self.n_scaling_factors
        )

        self.fifos_dse_space = {}

        for fifo in self.sim_env.fifos:
            fifo_id = fifo.id
            try:
                fifo_depths = self.sim_env.trace_base.compiled.get_fifo_design_space(
                    [fifo_id], fifo.width
                )
                if fifo_depths == [2]:
                    fifo_depths = [2, 64 * fifo.width]
                print(f"FIFO {fifo_id} design space: {fifo_depths}")
            except Exception:
                fifo_depths = [2, 64 * fifo.width]
            self.fifos_dse_space[fifo_id] = fifo_depths

        self.fifos_dse_space_bounds = []
        for fifo_id in self.fifo_ids:
            bounds = (0, len(self.fifos_dse_space[fifo_id]) - 1)
            self.fifos_dse_space_bounds.append(bounds)

    def solve(self) -> list[EvalResult]:
        results = []

        results_all = []

        for idx in range(self.n_scaling_factors):
            scaling_factor_latency = self.dual_objective_scaling_factors[idx, 0]
            scaling_factor_bram = self.dual_objective_scaling_factors[idx, 1]

            def objective_function(x: np.ndarray) -> float:
                x = round(x, round_type=self.round_type).astype(int)
                # sample = dict(zip(self.fifo_ids, x))  # Directly construct dictionary
                sample = {}
                for fifo_id, x_val in zip(self.fifo_ids, x):
                    selected_fifo_size = self.fifos_dse_space[fifo_id][x_val]
                    sample[fifo_id] = selected_fifo_size

                y = self.sim_env.eval_solution_single(sample)
                results_all.append(y)

                if y.deadlock:
                    return np.inf

                return (
                    scaling_factor_latency * y.latency
                    + scaling_factor_bram * y.bram_usage_total
                )

            bounds = Bounds(
                lb=[l for l, u in self.fifos_dse_space_bounds],
                ub=[u for l, u in self.fifos_dse_space_bounds],
            )

            x0 = None
            if self.init_with_largest:
                x0 = np.array(
                    [
                        len(self.fifos_dse_space[fifo_id]) - 1
                        for fifo_id in self.fifo_ids
                    ]
                )

            result = dual_annealing(
                objective_function,
                bounds=bounds,
                maxfun=self.maxfun,
                no_local_search=True,
                rng=7,
                x0=x0,
            )
            x_rounded = round(result.x, self.round_type)
            x_python = x_rounded.tolist()
            x_python_int = [int(x) for x in x_python]

            sol_sample = {
                fifo_id: size for fifo_id, size in zip(self.fifo_ids, x_python_int)
            }
            sol_eval_results = self.sim_env.eval_solution_single(sol_sample)
            results.append(sol_eval_results)

        return results_all


class GroupedDiscreteSimulatedAnnealingOptimizer(FIFOOptimizer):
    def __init__(
        self,
        sim_env: LSEnv,
        maxfun: int = 100,
        n_scaling_factors: int = 8,
        round_type: ROUND_TYPE = ROUND_TYPE.RINT,
        init_with_largest: bool = False,
    ):
        super().__init__(sim_env)
        self.maxfun = maxfun
        self.round_type = round_type
        self.init_with_largest = init_with_largest

        self.fifo_ids = [fifo.id for fifo in self.sim_env.fifos]
        self.n_scaling_factors = n_scaling_factors
        self.dual_objective_scaling_factors = compute_dual_obj_scaling_factors(
            self.n_scaling_factors
        )

        # self.fifos_dse_space = {}
        # for fifo in self.sim_env.fifos:
        #     fifo_id = fifo.id
        #     fifo_depths = self.sim_env.trace_base.compiled.get_fifo_design_space(
        #         [fifo_id], fifo.width
        #     )
        #     self.fifos_dse_space[fifo_id] = fifo_depths

        # self.fifos_dse_space_bounds = []
        # for fifo_id in self.fifo_ids:
        #     bounds = (0, len(self.fifos_dse_space[fifo_id]) - 1)
        #     self.fifos_dse_space_bounds.append(bounds)

        self.fifo_groups: dict[str, list[ResolvedStream]] = defaultdict(list)
        for fifo in self.sim_env.fifos:
            self.fifo_groups[fifo.get_display_name()].append(fifo)

        self.fifo_group_names = list(self.fifo_groups.keys())

        self.fifo_ids_groups = defaultdict(list)
        for k, v in self.fifo_groups.items():
            for fifo in v:
                self.fifo_ids_groups[k].append(fifo.id)

        self.grouped_fifos_dse_space = {}
        for fifo_group, fifos in self.fifo_groups.items():
            self.grouped_fifos_dse_space[fifo_group] = (
                self.sim_env.trace_base.compiled.get_fifo_design_space(
                    [fifo.id for fifo in fifos], fifos[0].width
                )
            )

        self.fifo_group_bounds: list[tuple[int, int]] = []
        for fifo_group in self.fifo_group_names:
            bounds = (0, len(self.grouped_fifos_dse_space[fifo_group]) - 1)
            self.fifo_group_bounds.append(bounds)

        # print(self.fifo_group_bounds)

    def solve(self) -> list[EvalResult]:
        results = []

        results_all = []

        for idx in range(self.n_scaling_factors):
            scaling_factor_latency = self.dual_objective_scaling_factors[idx, 0]
            scaling_factor_bram = self.dual_objective_scaling_factors[idx, 1]

            def objective_function(x: np.ndarray) -> float:
                x = round(x, round_type=self.round_type).astype(int)

                sample = {}
                for fifo_group, x_val in zip(self.fifo_group_names, x):
                    selected_fifo_size = self.grouped_fifos_dse_space[fifo_group][x_val]
                    for fifo_id in self.fifo_ids_groups[fifo_group]:
                        sample[fifo_id] = selected_fifo_size

                y = self.sim_env.eval_solution_single(sample)
                results_all.append(y)

                if y.deadlock:
                    return np.inf

                return (
                    scaling_factor_latency * y.latency
                    + scaling_factor_bram * y.bram_usage_total
                )

            bounds = Bounds(
                lb=[l for l, u in self.fifo_group_bounds],
                ub=[u for l, u in self.fifo_group_bounds],
            )

            x0 = None
            if self.init_with_largest:
                x0 = np.array(
                    [
                        len(self.grouped_fifos_dse_space[fifo_group]) - 1
                        for fifo_group in self.fifo_group_names
                    ]
                )

            result: OptimizeResult = dual_annealing(
                objective_function,
                bounds=bounds,
                maxfun=self.maxfun,
                no_local_search=True,
                rng=7,
                x0=x0,
            )
            x_rounded = round(result.x, self.round_type)
            x_python = x_rounded.tolist()
            x_python_int = [int(x) for x in x_python]

            sol_sample = {
                fifo_id: size for fifo_id, size in zip(self.fifo_ids, x_python_int)
            }
            sol_eval_results = self.sim_env.eval_solution_single(sol_sample)
            results.append(sol_eval_results)

        return results_all


class GroupRandomInitializedSimulatedAnnealingOptimizer(FIFOOptimizer):
    def __init__(
        self,
        sim_env: LSEnv,
        maxfun: int = 50,
        round_type: ROUND_TYPE = ROUND_TYPE.RINT,
        n_samples: int = 1000,
    ):
        super().__init__(sim_env)
        self.maxfun = maxfun
        self.round_type = round_type
        self.n_samples = n_samples

    def solve(self) -> list[EvalResult]:
        self.opt_grouped_random_search = GroupRandomSearchOptimizer(
            self.sim_env,
            n_samples=self.n_samples,
            seed=7,
        )
        results_random_opt = self.opt_grouped_random_search.solve()
        # filter out any deadlock results
        results_random_opt = [
            result for result in results_random_opt if not result.deadlock
        ]
        assert len(results_random_opt) > 0, (
            "No valid results found in random search optimization."
        )

        pareto_mask = is_pareto_efficient_simple(results_random_opt)
        results_random_opt = [
            result for result, mask in zip(results_random_opt, pareto_mask) if mask
        ]

        all_results: list[EvalResult] = []
        for r in results_random_opt:
            assert not r.deadlock
            assert r.latency is not None
            assert r.bram_usage_total is not None

            self.opt_simulated_annealing = SimulatedAnnealingOptimizer(
                self.sim_env,
                maxfun=self.maxfun,
                round_type=self.round_type,
                init_pool=[r],
            )
            results_simulated_annealing = self.opt_simulated_annealing.solve()
            all_results.extend(results_simulated_annealing)
        return all_results


class HeuristicOptimizer(FIFOOptimizer):
    level_sets = [0.01, 0.05, 0.1, 0.2, 0.5, 1.0]

    def solve(self) -> list[EvalResult]:
        all_evals = []
        for level in self.level_sets:
            print(f"Running heuristic optimization for level: {level}...")

            base_depths = {}
            for fifo, fifo_io in self.sim_env.simulation_base.fifo_io.items():
                fifo_id = fifo.id
                base_depths[fifo_id] = max(fifo_io.get_observed_depth(), 2)

            eval_results = self.sim_env.eval_solution_single(base_depths)
            all_evals.append(eval_results)
            assert not eval_results.deadlock

            base_latency = eval_results.latency
            base_bram_usage_total = eval_results.bram_usage_total

            assert base_latency is not None
            assert base_bram_usage_total is not None

            fifo_ids_sorted_by_depth = sorted(
                base_depths.keys(), key=lambda fifo_id: base_depths[fifo_id]
            )

            fifo_ids_larger_than_two = [
                fifo_id
                for fifo_id in fifo_ids_sorted_by_depth
                if base_depths[fifo_id] > 2
            ]

            working_set_of_depths = deepcopy(base_depths)

            for fifo_id in fifo_ids_larger_than_two:
                new_sample = deepcopy(working_set_of_depths)
                new_sample[fifo_id] = 2
                eval_results_case = self.sim_env.eval_solution_single(new_sample)
                all_evals.append(eval_results_case)
                if eval_results_case.deadlock:
                    continue
                assert eval_results_case.latency is not None
                if eval_results_case.latency > base_latency * 1.01:
                    continue

                working_set_of_depths[fifo_id] = 2

            eval_results_final = self.sim_env.eval_solution_single(
                working_set_of_depths
            )
            all_evals.append(eval_results_final)
            assert not eval_results_final.deadlock

        return all_evals


T_FIFOOptimizer = Union[
    RandomSearchOptimizer,
    GroupRandomSearchOptimizer,
    GroupExhaustiveOptimizer,
    SimulatedAnnealingOptimizer,
    GroupRandomInitializedSimulatedAnnealingOptimizer,
    HeuristicOptimizer,
    DiscreteSimulatedAnnealingOptimizer,
    GroupedDiscreteSimulatedAnnealingOptimizer,
]
