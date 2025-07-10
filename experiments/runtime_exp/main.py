import itertools
import time
from concurrent.futures import ThreadPoolExecutor
from copy import deepcopy
from functools import partial
from pathlib import Path
from pprint import pp

import numpy as np
import pandas as pd
from dotenv import dotenv_values
from matplotlib import pyplot as plt

from fifo_opt.automation import TestCase
from fifo_opt.opt_env import LSEnv, is_pareto_efficient_simple
from fifo_opt.solvers import (
    DiscreteSimulatedAnnealingOptimizer,
    GroupedDiscreteSimulatedAnnealingOptimizer,
    GroupRandomInitializedSimulatedAnnealingOptimizer,
    GroupRandomSearchOptimizer,
    HeuristicOptimizer,
    RandomSearchOptimizer,
    T_FIFOOptimizer,
    count_configs,
    count_configs_grouped,
)

# EXPERIMENT CONFIGURATION
# ======================

# Design to test (should match a design name from the available designs)
selected_design_name = "k15mmtree"

# Sampling parameters
MAX_SAMPLES = 50_000
N_STEPS = 10

# Heuristic score parameters
ALPHA = 0.7  # Weight for latency vs BRAM (0.7 means 70% latency, 30% BRAM)

# Plotting parameters
FIGURE_SIZE = (12, 8)
DPI = 300

# ======================

DIR_CURRENT = Path(__file__).parent

DIR_FIGURES = DIR_CURRENT / "figures"
if not DIR_FIGURES.exists():
    DIR_FIGURES.mkdir(exist_ok=True)

DIR_DATA = DIR_CURRENT / "data"
if not DIR_DATA.exists():
    DIR_DATA.mkdir(exist_ok=True)

ENV_FILE: Path = DIR_CURRENT.parent / ".env"
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


designs_all_dirs: list[Path] = sorted(
    [d for d in DIR_PRE_SYNTH.glob("*") if d.is_dir()]
)

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


selected_design = next(
    (design for design in designs_all if design.name == selected_design_name), None
)
if selected_design is None:
    raise ValueError(f"Design {selected_design_name} not found in the list of designs.")

### Config Counting ###
config_counting_env = LSEnv(
    selected_design.solution_dir,
    env_vars_extra={
        "PRJ_PATH": str(selected_design.prj_path.resolve().absolute()),
    },
)
num_configs = count_configs(config_counting_env)
num_configs_grouped = count_configs_grouped(config_counting_env)
print(f"Total number of configurations: {num_configs}")
print(f"Total number of grouped configurations: {num_configs_grouped}")
### Done ###


def run_baseline_eval(design: TestCase) -> dict:
    print(f"Running design: {design.dir}")
    prj_path = design.prj_path.resolve().absolute()

    sim_env = LSEnv(
        design.solution_dir,
        env_vars_extra={
            "PRJ_PATH": str(prj_path),
        },
    )

    baseline_results = sim_env.eval_solution_default()
    assert baseline_results.deadlock is False

    baseline_latency = baseline_results.latency
    baseline_bram_usage_total = baseline_results.bram_usage_total
    assert baseline_latency is not None
    assert baseline_bram_usage_total is not None

    baseline_latency_bram_product = baseline_latency * baseline_bram_usage_total

    return {
        "latency": baseline_latency,
        "bram": baseline_bram_usage_total,
        "latency_bram_product": baseline_latency_bram_product,
        "design_name": design.dir.name,
    }


result_baseline = run_baseline_eval(selected_design)


n_sample_values_np = np.linspace(10, MAX_SAMPLES, N_STEPS, endpoint=True)
n_sample_values: list[int] = np.rint(n_sample_values_np).astype(int).tolist()  # type: ignore

# Define multiple optimizers to test
optimizers_to_test = [
    {
        "name": "RandomSearchOptimizer",
        "class": RandomSearchOptimizer,
        "param_name": "n_samples",
    },
    {
        "name": "GroupRandomSearchOptimizer",
        "class": GroupRandomSearchOptimizer,
        "param_name": "n_samples",
    },
    # Add more optimizers here as needed:
    # {
    #     "name": "DiscreteSimulatedAnnealingOptimizer",
    #     "class": DiscreteSimulatedAnnealingOptimizer,
    #     "param_name": "n_samples",
    # },
    # {
    #     "name": "GroupedDiscreteSimulatedAnnealingOptimizer",
    #     "class": GroupedDiscreteSimulatedAnnealingOptimizer,
    #     "param_name": "n_samples",
    # },
]


def run_optimizer_experiment(
    optimizer_info: dict, n_samples: int, design: TestCase
) -> dict:
    """Run a single optimizer experiment with given parameters."""
    optimizer_name = optimizer_info["name"]
    optimizer_class = optimizer_info["class"]
    param_name = optimizer_info["param_name"]

    print(f"Running {optimizer_name} with {param_name}={n_samples}")

    design_copy = deepcopy(design)
    print(f"Running design: {design_copy.dir}")
    prj_path = design_copy.prj_path.resolve().absolute()

    sim_env = LSEnv(
        design_copy.solution_dir,
        env_vars_extra={
            "PRJ_PATH": str(prj_path),
        },
    )

    # Create optimizer with the appropriate parameter
    optimizer_kwargs = {param_name: n_samples}
    optimizer = optimizer_class(sim_env, **optimizer_kwargs)

    try:
        time_zero = time.perf_counter()
        results = optimizer.solve()
    except Exception as e:
        print(f"Error in design {design_copy.dir} with {optimizer_name}: {e}")
        raise e

    return {
        "optimizer": optimizer_name,
        "n_samples": n_samples,
        "time_zero": time_zero,
        "points": results,
    }


# Run experiments for all optimizers
data = []

for optimizer_info in optimizers_to_test:
    for n in n_sample_values:
        result = run_optimizer_experiment(optimizer_info, n, selected_design)
        data.append(result)


def huristic_score(latency, bram, base_latency, base_bram, alpha=ALPHA):
    relative_latency = latency / base_latency
    if base_bram == 0:
        base_bram = 1

    relative_bram = bram / base_bram

    score = alpha * relative_latency + (1 - alpha) * relative_bram
    return score


# Process data by optimizer for plotting
optimizer_data = {}
for d in data:
    optimizer_name = d["optimizer"]
    if optimizer_name not in optimizer_data:
        optimizer_data[optimizer_name] = []
    optimizer_data[optimizer_name].append(d)

# make a single plot with all the data so far
# the idea is that n_samples is on the x-axis and the best heuristic score is on the y-axis

fig, ax = plt.subplots(figsize=FIGURE_SIZE)

# Plot each optimizer separately
colors = ["blue", "green", "orange", "purple", "brown", "pink"]
markers = ["o", "s", "^", "v", "D", "x"]

for i, (optimizer_name, optimizer_results) in enumerate(optimizer_data.items()):
    points = []
    # the zero point is the baseline
    points.append(
        (
            0,
            huristic_score(
                result_baseline["latency"],
                result_baseline["bram"],
                result_baseline["latency"],
                result_baseline["bram"],
            ),
        )
    )

    for d in optimizer_results:
        n_samples = d["n_samples"]
        all_points = d["points"]
        print(
            f"Optimizer: {optimizer_name}, Number of points: {len(all_points)}, n_samples: {n_samples}"
        )

        # non deadlocking points
        all_points = [p for p in all_points if not p.deadlock]
        if not all_points:
            print(f"No valid points for {optimizer_name} with n_samples={n_samples}")
            continue

        scores = [
            huristic_score(
                point.latency,
                point.bram_usage_total,
                result_baseline["latency"],
                result_baseline["bram"],
            )
            for point in all_points
        ]
        best_point, best_score = min(zip(all_points, scores), key=lambda x: x[1])
        points.append((n_samples, best_score))
        print(f"Best score for {optimizer_name}: {best_score}")

    points = sorted(points, key=lambda x: x[0])
    x_values, y_values = zip(*points)

    color = colors[i % len(colors)]
    marker = markers[i % len(markers)]
    ax.plot(
        x_values,
        y_values,
        marker=marker,
        label=optimizer_name,
        color=color,
        linewidth=2,
    )

# Add baseline line
ax.axhline(
    y=huristic_score(
        result_baseline["latency"],
        result_baseline["bram"],
        result_baseline["latency"],
        result_baseline["bram"],
    ),
    color="r",
    linestyle="--",
    label="Baseline",
    linewidth=2,
)

frac = 1000
num_configs_grouped_frac = int(round(num_configs_grouped / frac))
ax.axvline(
    x=num_configs_grouped_frac,
    color="black",
    linestyle="--",
    label=f"{1 / frac * 100}% of All Grouped Configs ({num_configs_grouped_frac})",
    linewidth=2,
)

ax.set_xlabel("Number of Samples", fontsize=12)
ax.set_ylabel("Heuristic Score (α×Relative Latency + (1-α)×Relative BRAM)", fontsize=12)
ax.set_title("Optimizer Performance Comparison", fontsize=14)
ax.legend(fontsize=10)
ax.grid(True, alpha=0.3)
ax.set_axisbelow(True)

plt.tight_layout()
plt.savefig(DIR_FIGURES / "multi_optimizer_performance_comparison.png", dpi=DPI)
plt.show()


# also make an iso time plot
fig, ax = plt.subplots(figsize=FIGURE_SIZE)

# Plot each optimizer separately for iso-time
for i, (optimizer_name, optimizer_results) in enumerate(optimizer_data.items()):
    points_iso_time = []
    # the zero point is the baseline
    points_iso_time.append(
        (
            0,
            huristic_score(
                result_baseline["latency"],
                result_baseline["bram"],
                result_baseline["latency"],
                result_baseline["bram"],
            ),
        )
    )

    for d in optimizer_results:
        n_samples = d["n_samples"]
        all_points = d["points"]
        print(
            f"Optimizer: {optimizer_name}, Number of points: {len(all_points)}, n_samples: {n_samples}"
        )

        # non deadlocking points
        all_points = [p for p in all_points if not p.deadlock]
        if not all_points:
            print(f"No valid points for {optimizer_name} with n_samples={n_samples}")
            continue

        scores = [
            huristic_score(
                point.latency,
                point.bram_usage_total,
                result_baseline["latency"],
                result_baseline["bram"],
            )
            for point in all_points
        ]
        best_point, best_score = min(zip(all_points, scores), key=lambda x: x[1])
        print(f"Best score for {optimizer_name}: {best_score}")

        time_zero = d["time_zero"]

        timestamps = set()
        for point in all_points:
            if point.timestamp is not None:
                timestamps.add(point.timestamp)

        if len(timestamps) != 1:
            print(
                f"Warning: Expected 1 timestamp, got {len(timestamps)} for {optimizer_name}"
            )
            if not timestamps:
                continue

        best_time = timestamps.pop()
        best_time = best_time - time_zero

        points_iso_time.append((best_time, best_score))

    points_iso_time = sorted(points_iso_time, key=lambda x: x[0])
    if len(points_iso_time) > 1:  # Only plot if we have data points
        x_values_iso, y_values_iso = zip(*points_iso_time)

        color = colors[i % len(colors)]
        marker = markers[i % len(markers)]
        ax.plot(
            x_values_iso,
            y_values_iso,
            marker=marker,
            label=optimizer_name,
            color=color,
            linewidth=2,
        )

# Add baseline line
ax.axhline(
    y=huristic_score(
        result_baseline["latency"],
        result_baseline["bram"],
        result_baseline["latency"],
        result_baseline["bram"],
    ),
    color="r",
    linestyle="--",
    label="Baseline",
    linewidth=2,
)

ax.set_xlabel("Time (seconds)", fontsize=12)
ax.set_ylabel("Heuristic Score (α×Relative Latency + (1-α)×Relative BRAM)", fontsize=12)
ax.set_title("Optimizer Performance Comparison (Iso Time)", fontsize=14)
ax.legend(fontsize=10)
ax.grid(True, alpha=0.3)
ax.set_axisbelow(True)

plt.tight_layout()
plt.savefig(DIR_FIGURES / "multi_optimizer_performance_iso_time.png", dpi=DPI)
plt.show()

# Save data to CSV for further analysis
df_data = []
for d in data:
    optimizer_name = d["optimizer"]
    n_samples = d["n_samples"]
    all_points = d["points"]

    # non deadlocking points
    valid_points = [p for p in all_points if not p.deadlock]

    if valid_points:
        scores = [
            huristic_score(
                point.latency,
                point.bram_usage_total,
                result_baseline["latency"],
                result_baseline["bram"],
            )
            for point in valid_points
        ]
        best_point, best_score = min(zip(valid_points, scores), key=lambda x: x[1])

        time_zero = d["time_zero"]
        timestamps = [
            point.timestamp for point in valid_points if point.timestamp is not None
        ]
        runtime = max(timestamps) - time_zero if timestamps else 0

        df_data.append(
            {
                "optimizer": optimizer_name,
                "n_samples": n_samples,
                "best_score": best_score,
                "best_latency": best_point.latency,
                "best_bram": best_point.bram_usage_total,
                "runtime_seconds": runtime,
                "num_valid_points": len(valid_points),
                "num_total_points": len(all_points),
            }
        )

df = pd.DataFrame(df_data)
df.to_csv(DIR_DATA / "multi_optimizer_comparison_results.csv", index=False)
print(f"Results saved to {DIR_DATA / 'multi_optimizer_comparison_results.csv'}")


def print_results_summary(df: pd.DataFrame):
    """Print a detailed summary of the optimization results."""
    print("\n" + "=" * 60)
    print("OPTIMIZATION RESULTS SUMMARY")
    print("=" * 60)

    print("\nBaseline Performance:")
    print(f"  Latency: {result_baseline['latency']}")
    print(f"  BRAM: {result_baseline['bram']}")
    print(
        f"  Heuristic Score: {huristic_score(result_baseline['latency'], result_baseline['bram'], result_baseline['latency'], result_baseline['bram']):.4f}"
    )

    for optimizer_name in df["optimizer"].unique():
        optimizer_df = df[df["optimizer"] == optimizer_name]
        best_result = optimizer_df.loc[optimizer_df["best_score"].idxmin()]

        print(f"\n{optimizer_name}:")
        print(
            f"  Best Score: {best_result['best_score']:.4f} (at n_samples={best_result['n_samples']})"
        )
        print(f"  Best Latency: {best_result['best_latency']}")
        print(f"  Best BRAM: {best_result['best_bram']}")
        print(f"  Runtime: {best_result['runtime_seconds']:.2f} seconds")
        print(
            f"  Success Rate: {optimizer_df['num_valid_points'].sum()}/{optimizer_df['num_total_points'].sum()} ({100 * optimizer_df['num_valid_points'].sum() / optimizer_df['num_total_points'].sum():.1f}%)"
        )

        # Performance improvement over baseline
        improvement = (1 - best_result["best_score"]) * 100
        print(f"  Improvement over baseline: {improvement:.1f}%")


print_results_summary(df)

print("\nDetailed Statistics by Optimizer:")
print(
    df.groupby("optimizer")[["best_score", "runtime_seconds"]].agg(
        ["mean", "min", "max"]
    )
)
