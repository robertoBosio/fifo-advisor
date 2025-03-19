from abc import ABC, abstractmethod
import asyncio
from pathlib import Path
from lightningsim.model import Solution
from lightningsim.runner import Runner, RunnerStep
from lightningsim.trace_file import ResolvedTrace
import numpy as np

import os

class FIFOOptimizer(ABC):
    def __init__(self, vitis_hls_solution_dir: Path, min_fifo_size: int = 2, env_vars_extra: dict[str, str] = {}):
        self.vitis_hls_solution_dir = vitis_hls_solution_dir
        self.min_fifo_size = min_fifo_size
        self.env_vars_extra = env_vars_extra

        for key, value in env_vars_extra.items():
            os.environ[key] = value

        self.solution = Solution(self.vitis_hls_solution_dir)
        self.runner = Runner(self.solution)

        self.runner.steps[RunnerStep.ANALYZING_PROJECT].on_start(lambda _: print("Analyzing project..."))
        self.runner.steps[RunnerStep.WAITING_FOR_BITCODE].on_start(lambda _: print("Waiting for bitcode to be generated..."))
        self.runner.steps[RunnerStep.GENERATING_SUPPORT_CODE].on_start(lambda _: print("Generating support code..."))
        self.runner.steps[RunnerStep.LINKING_BITCODE].on_start(lambda _: print("Linking bitcode..."))
        self.runner.steps[RunnerStep.COMPILING_BITCODE].on_start(lambda _: print("Compiling bitcode..."))
        self.runner.steps[RunnerStep.LINKING_TESTBENCH].on_start(lambda _: print("Linking testbench..."))
        self.runner.steps[RunnerStep.RUNNING_TESTBENCH].on_start(lambda _: print("Running testbench..."))
        self.runner.steps[RunnerStep.PARSING_SCHEDULE_DATA].on_start(lambda _: print("Parsing schedule data from C synthesis..."))
        self.runner.steps[RunnerStep.RESOLVING_TRACE].on_start(lambda _: print("Resolving dynamic schedule from trace..."));

        self.trace_base = asyncio.run(self.runner.run())
        self.simulation_base = self.trace_base.compiled.execute(self.trace_base.params)

        self.fifos = self.trace_base.fifos
        self.num_fifos = len(self.trace_base.fifos)

        self.fifo_sizes_base = []
        for fifo in self.fifos:
            fifo_id = fifo.id
            fifo_depth = self.trace_base.params.fifo_depths[fifo_id]
            self.fifo_sizes_base.append(fifo_depth)
            

    def eval_solution_single(self, x: np.ndarray) -> float:
        raise NotImplementedError

    def eval_solution_parallel(self, x: np.ndarray) -> np.ndarray:
        raise NotImplementedError
        
    @abstractmethod
    def solve(self) -> dict[int, int] | None:
        ...
