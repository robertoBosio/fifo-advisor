import shutil
from pathlib import Path
from pprint import pp
from tempfile import TemporaryDirectory

import numpy as np
from dotenv import dotenv_values
from joblib import Parallel, delayed
from matplotlib import pyplot as plt

from fifo_opt.automation import TestCase
from fifo_opt.solvers import RandomSearchOptimizer

DIR_CURRENT = Path(__file__).parent

DIR_FIGURES = DIR_CURRENT / "figures"
if not DIR_FIGURES.exists():
    DIR_FIGURES.mkdir(exist_ok=True)


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
# sort by total dir size
# designs_all_dirs.sort(key=lambda d: sum(f.stat().st_size for f in d.rglob("*")))
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

designs_to_keep = ["Autoencoder"]
designs_all = [
    design
    for design in designs_all
    if any(design.name.startswith(d) for d in designs_to_keep)
]


pp(list(map(lambda x: x.dir.name, designs_all)))


# I want to test deigsnt o see which ones take longer than X seconds to call RandomSearchOptimizer
#  I want to recoed any that take less than 30 seconds
# i need to check for a timeout


# def check_design_time(design: TestCase) -> bool:
#     prj_path = design.prj_path.resolve().absolute()
#     with TemporaryDirectory() as tmp_dir:
#         shutil.copytree(prj_path, tmp_dir, dirs_exist_ok=True)
#         optimizer_random_search = RandomSearchOptimizer(
#             Path(tmp_dir),
#             env_vars_extra={
#                 "PRJ_PATH": str(prj_path),
#             },
#             n_samples=100,
#         )
#         try:
#             optimizer_random_search.solve()
#             return True
#         except Exception as e:
#             print(f"Error in design {design.dir}: {e}")
#             return False


designs_all_filtered = designs_all[:1]

for design in designs_all_filtered:
    print(f"Running design: {design.dir}")
    prj_path = design.prj_path.resolve().absolute()

    optimizer_random_search = RandomSearchOptimizer(
        design.solution_dir,
        env_vars_extra={
            "PRJ_PATH": str(prj_path),
        },
        n_samples=2000,
    )
    results = optimizer_random_search.solve()
    results_no_deadlock = [result for result in results if not result.deadlock]

    n_total = len(results)
    n_no_deadlock = len(results_no_deadlock)
    n_deadlock = len(results) - n_no_deadlock

    vals_latency = [
        result.latency for result in results_no_deadlock if result.latency is not None
    ]
    vals_bram_usage_total = [
        result.bram_usage_total
        for result in results_no_deadlock
        if result.bram_usage_total is not None
    ]

    fig, ax = plt.subplots(1, 1, figsize=(6, 6))

    ax.grid(which="both", linestyle="--", linewidth=0.5)
    ax.grid(which="major", linestyle="--", linewidth=0.8)
    ax.set_axisbelow(True)
    ax.scatter(vals_bram_usage_total, vals_latency)
    ax.set_xlabel("BRAM Usage Total")
    ax.set_ylabel("Latency")
    ax.set_title(f'FIFO Design Space for Design "{design.dir.name}"')

    # x_min = 0
    # x_max = max(vals_bram_usage_total) * 1.1
    # ax.set_xlim(x_min, x_max)

    # def round_down_to_nearest_power_of_10(x):
    #     if x <= 0:
    #         return 0
    #     power = int(np.floor(np.log10(x)))
    #     return 10**power

    # def round_up_to_nearest_power_of_10(x):
    #     if x <= 0:
    #         return 0
    #     power = int(np.ceil(np.log10(x)))
    #     return 10**power

    # y_min = round_down_to_nearest_power_of_10(min(vals_latency)) * 0.9
    # y_max = round_up_to_nearest_power_of_10(max(vals_latency)) * 1.1
    # ax.set_ylim(y_min, y_max)

    # ax.set_yscale("log")

    fig.tight_layout()

    fig_path = DIR_FIGURES / f"{design.dir.name}__latency_vs_bram.png"
    fig.savefig(fig_path, dpi=300)
