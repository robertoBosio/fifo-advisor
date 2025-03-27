import multiprocessing
import random
import time
from pathlib import Path

import pandas as pd
from dotenv import dotenv_values

from fifo_opt.automation import TestCase
from fifo_opt.opt_env import LSEnv

DIR_CURRENT = Path(__file__).parent

DIR_FIGURES = DIR_CURRENT / "figures"
if not DIR_FIGURES.exists():
    DIR_FIGURES.mkdir(exist_ok=True)

DIR_DATA = DIR_CURRENT / "data"
if not DIR_DATA.exists():
    DIR_DATA.mkdir(exist_ok=True)

ENV_FILE: Path = DIR_CURRENT / ".env"
if ENV_FILE.exists():
    env_vars = dotenv_values(ENV_FILE)
else:
    raise FileNotFoundError(
        f"Environment file {ENV_FILE} not found. Please create it with the required variables."
    )
if "DIR_PRE_SYNTH" in env_vars:
    if env_vars["DIR_PRE_SYNTH"] is None:
        raise ValueError(
            "Environment variable 'DIR_PRE_SYNTH' is set to None. Please set it to a valid path."
        )
    DIR_PRE_SYNTH = Path(env_vars["DIR_PRE_SYNTH"])
else:
    raise KeyError(
        "Environment variable 'DIR_PRE_SYNTH' not found in .env file. Please add it."
    )


designs_all_dirs = sorted([d for d in DIR_PRE_SYNTH.glob("*") if d.is_dir()])


designs_all = [
    TestCase.from_dir(design_dir, design_dir.name.split("__")[0])
    for design_dir in designs_all_dirs
]

designs_to_ignore = ["MultiHeadSelfAttention1"]
designs_all = [
    design
    for design in designs_all
    if not any(design.name.startswith(d) for d in designs_to_ignore)
]

designs_all = [design for design in designs_all if design.dir.name.endswith("__opt5")]

designs_all_filtered = designs_all[:]


N_SAMPLES = 1000


def run_single(design: TestCase):
    prj_path = design.prj_path.resolve().absolute()

    sim_env = LSEnv(
        design.solution_dir,
        env_vars_extra={
            "PRJ_PATH": str(prj_path),
        },
    )

    fifos_dse_space = {}
    for fifo in sim_env.fifos:
        fifo_id = fifo.id
        fifo_depths = sim_env.trace_base.compiled.get_fifo_design_space(
            [fifo_id], fifo.width
        )
        fifos_dse_space[fifo_id] = fifo_depths

    r = random.Random(7)
    sampled_configs = []
    for _ in range(N_SAMPLES):
        sample: dict[int, int] = {}
        for fifo_id, fifo_depths in fifos_dse_space.items():
            sample[fifo_id] = r.choice(fifo_depths)
        sampled_configs.append(sample)

    times = []
    for i, sample in enumerate(sampled_configs):
        t0 = time.perf_counter_ns()
        sim_env.eval_solution_single(sample)
        t1 = time.perf_counter_ns()
        elapsed = t1 - t0
        elapsed_s = elapsed / 1e9
        times.append(elapsed_s)

    avg_time = sum(times) / len(times)
    median_time = sorted(times)[len(times) // 2]

    # parallel
    t0 = time.perf_counter_ns()
    sim_env.eval_solution_parallel(sampled_configs)
    t1 = time.perf_counter_ns()
    elapsed: int = t1 - t0
    time_parallel = elapsed / 1e9
    time_parallel_amortized = time_parallel / N_SAMPLES
    print(f"Time parallel: {time_parallel:.3f} s")
    print(f"Time parallel amortized: {time_parallel_amortized:.9f} s")

    return {
        "design_name": design.name,
        "n_samples": N_SAMPLES,
        "times": times,
        "median_time": median_time,
        "avg_time": avg_time,
        "time_parallel": time_parallel,
        "time_parallel_amortized": time_parallel_amortized,
    }


N_JOBS = 48
with multiprocessing.Pool(N_JOBS) as pool:
    data_all = pool.map(run_single, designs_all_filtered, chunksize=1)

for data in data_all:
    design_name = data["design_name"]
    times = data["times"]
    median_time = data["median_time"]
    avg_time = data["avg_time"]
    time_parallel = data["time_parallel"]
    time_parallel_amortized = data["time_parallel_amortized"]

    print(f"Design: {design_name}")
    print(f"Avg time: {avg_time:.6f} s")
    print(f"Median time: {median_time:.6f} s")
    print(f"Time parallel: {time_parallel:.6f} s")
    print(f"Time parallel amortized: {time_parallel_amortized:.6f} s")
    print()

df_time = pd.DataFrame(data_all)
df_time.to_csv(DIR_DATA / "eval_time.csv", index=False)
