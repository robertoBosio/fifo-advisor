import asyncio
import os
import pickle
from abc import ABC, abstractmethod
from dataclasses import dataclass
from pathlib import Path
from tempfile import TemporaryDirectory

import dill
import numpy as np
from lightningsim.model import Solution
from lightningsim.runner import Runner, RunnerStep
from lightningsim.trace_file import ResolvedTrace


@dataclass
class EvalResult:
    fifo_sizes: dict[int, int]
    deadlock: bool

    latency: float | None
    bram_usage_total: int | None
    # bram_usage_per_fifo: dict[int, int] | None


class FIFOOptimizer(ABC):
    def __init__(
        self,
        vitis_hls_solution_dir: Path,
        min_fifo_size: int = 2,
        env_vars_extra: dict[str, str] = {},
    ):
        self.vitis_hls_solution_dir = vitis_hls_solution_dir
        self.min_fifo_size = min_fifo_size
        self.env_vars_extra = env_vars_extra

        for key, value in env_vars_extra.items():
            os.environ[key] = value

        self.solution = Solution(self.vitis_hls_solution_dir)
        self.runner = Runner(self.solution)

        self.runner.steps[RunnerStep.ANALYZING_PROJECT].on_start(
            lambda _: print("Analyzing project...")
        )
        self.runner.steps[RunnerStep.WAITING_FOR_BITCODE].on_start(
            lambda _: print("Waiting for bitcode to be generated...")
        )
        self.runner.steps[RunnerStep.GENERATING_SUPPORT_CODE].on_start(
            lambda _: print("Generating support code...")
        )
        self.runner.steps[RunnerStep.LINKING_BITCODE].on_start(
            lambda _: print("Linking bitcode...")
        )
        self.runner.steps[RunnerStep.COMPILING_BITCODE].on_start(
            lambda _: print("Compiling bitcode...")
        )
        self.runner.steps[RunnerStep.LINKING_TESTBENCH].on_start(
            lambda _: print("Linking testbench...")
        )
        self.runner.steps[RunnerStep.RUNNING_TESTBENCH].on_start(
            lambda _: print("Running testbench...")
        )
        self.runner.steps[RunnerStep.PARSING_SCHEDULE_DATA].on_start(
            lambda _: print("Parsing schedule data from C synthesis...")
        )
        self.runner.steps[RunnerStep.RESOLVING_TRACE].on_start(
            lambda _: print("Resolving dynamic schedule from trace...")
        )

        self.trace_base = asyncio.run(self.runner.run())
        self.simulation_base = self.trace_base.compiled.execute(self.trace_base.params)

        self.fifos = self.trace_base.fifos
        self.num_fifos = len(self.trace_base.fifos)

        self.fifo_sizes_base = []
        for fifo in self.fifos:
            fifo_id = fifo.id
            fifo_depth: int | None = self.trace_base.params.fifo_depths[fifo_id]
            self.fifo_sizes_base.append(fifo_depth)

    def eval_solution_single(self, x: dict[int, int]) -> EvalResult:
        base_params = self.trace_base.params
        fifo_widths: dict[int, int] = {
            fifo.id: fifo.width for fifo in self.trace_base.fifos
        }
        design_points = [x]

        dse_results = self.trace_base.compiled.dse(
            base_params, fifo_widths, design_points
        )
        assert len(dse_results) == 1
        dse_result = dse_results[0]

        fifo_sizes = x
        if dse_result.latency is None:
            deadlock = True
            latency = None
            bram_usage_total = None
        else:
            deadlock = False
            latency = dse_result.latency
            bram_usage_total = dse_result.bram_count

        return EvalResult(
            fifo_sizes=fifo_sizes,
            deadlock=deadlock,
            latency=latency,
            bram_usage_total=bram_usage_total,
        )

    def eval_solution_parallel(
        self, x_multiple: list[dict[int, int]]
    ) -> list[EvalResult]:
        results = []
        for x in x_multiple:
            result = self.eval_solution_single(x)
            results.append(result)
        return results

    @abstractmethod
    def solve(self) -> list[EvalResult] | None: ...
