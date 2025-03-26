import itertools
import multiprocessing
from pathlib import Path
from pprint import pp

import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import seaborn as sns
from matplotlib.axes import Axes
from matplotlib.figure import Figure

DIR_CURRENT = Path(__file__).parent

DIR_FIGURES = DIR_CURRENT / "figures"
if not DIR_FIGURES.exists():
    DIR_FIGURES.mkdir(exist_ok=True)

DIR_DATA = DIR_CURRENT / "data"
if not DIR_DATA.exists():
    DIR_DATA.mkdir(exist_ok=True)


df_baseline = pd.read_csv(DIR_DATA / "data_baseline.csv")
df_points = pd.read_csv(DIR_DATA / "data_points.csv")
df_search_counts = pd.read_csv(DIR_DATA / "data_search_counts.csv")

designs_to_remove = ["ResMLP__opt5", "k7mmtree_balanced__opt5"]
# designs_to_remove = ["ResMLP__opt4", "ResMLP__opt5", "k7mmtree_balanced__opt5"]

for design in designs_to_remove:
    df_baseline = df_baseline[df_baseline["design_name"] != design]
    df_points = df_points[df_points["design_name"] != design]
    df_search_counts = df_search_counts[df_search_counts["design_name"] != design]


# if design_name ends in __opt5 remove the __opt5 suffix
df_baseline["design_name"] = df_baseline["design_name"].str.replace("__opt5", "")
df_points["design_name"] = df_points["design_name"].str.replace("__opt5", "")
df_search_counts["design_name"] = df_search_counts["design_name"].str.replace(
    "__opt5", ""
)


designs = df_baseline["design_name"].unique().tolist()
optimizers = df_points["optimizer_name"].unique().tolist()
all_cases = itertools.product(designs, optimizers)


optimizer_to_color_map = {
    "random_search": "blue",
    "group_random_search": "green",
    "heuristic": "red",
    "init_simulated_annealing": "orange",
    "discrete_simulated_annealing": "purple",
    "grouped_discrete_simulated_annealing": "brown",
}

optimizer_to_name_map = {
    "random_search": "Random Search",
    "group_random_search": "Group Random Search",
    "heuristic": "Heuristic",
    "init_simulated_annealing": "Seeded Simulated Annealing",
    "discrete_simulated_annealing": "Discrete Simulated Annealing",
    "grouped_discrete_simulated_annealing_no_init": "Grouped Discrete Simulated Annealing",
}


def compute_area_under_curve(
    x_vals: list[int], y_vals: list[int]
) -> tuple[float, list[tuple[int, int]]]:
    # build a polygon
    points: list[tuple[int, int]] = []
    # start with (0, 0)
    points.append((0, 0))
    # get the y value of the first point
    y_first = y_vals[0]
    # add the first point
    points.append((0, y_first))
    # then add the rest of the points
    for x, y in zip(x_vals, y_vals):
        points.append((x, y))
    # add the last point
    points.append((x_vals[-1], 0))
    # add the origin point
    points.append((0, 0))
    # compute the area
    area = 0.0
    for i in range(len(points) - 1):
        x1, y1 = points[i]
        x2, y2 = points[i + 1]
        area += (x2 - x1) * (y1 + y2) / 2.0
    return area, points


def compute_hypervolume(
    ref_point: tuple[int, int], x_vals: list[int], y_vals: list[int]
) -> tuple[float, list[tuple[int, int]]]:
    points: list[tuple[int, int]] = []
    points.append(ref_point)

    # first point is the point with the min x value but same y value as the ref point
    min_x = min(x_vals)
    min_y = ref_point[1]
    points.append((min_x, min_y))
    # then add the rest of the points
    for x, y in zip(x_vals, y_vals):
        points.append((x, y))

    # then the last point is the point with the same x value as the ref point but min y value
    max_x = ref_point[0]
    max_y = min(y_vals)
    points.append((max_x, max_y))
    # then the last point is the ref point
    points.append(ref_point)
    # compute the area
    area = 0.0
    for i in range(len(points) - 1):
        x1, y1 = points[i]
        x2, y2 = points[i + 1]
        area += (x2 - x1) * (y1 + y2) / 2.0
    area = abs(area)
    return area, points


best_pareto_solution = {}

# for each design and optmizer find the lowest latency bram product and compute the speed up oevr the baseline
data_improvement = []
data_hypervolume = []
for design, optimizer in all_cases:
    baseline_data_case = df_baseline[(df_baseline["design_name"] == design)].copy()
    assert len(baseline_data_case) == 1

    optimizer_data_case = df_points[
        (df_points["design_name"] == design)
        & (df_points["optimizer_name"] == optimizer)
    ].copy()

    # sort pereto front
    optimizer_data_case = optimizer_data_case.sort_values(
        ["latency", "bram"], ascending=[False, True]
    )

    baseline_latency = baseline_data_case["latency"].values[0].item()
    baseline_bram = baseline_data_case["bram"].values[0].item()
    baseline_modified_product = (baseline_bram + 1) * baseline_latency
    baseline_modified_distance = ((baseline_bram + 1) ** 2 + baseline_latency**2) ** 0.5

    optimizer_data_case["modified_product"] = (
        optimizer_data_case["bram"] + 1
    ) * optimizer_data_case["latency"]

    best_modified_product = optimizer_data_case["modified_product"].min()
    best_modified_product_row = optimizer_data_case[
        optimizer_data_case["modified_product"] == best_modified_product
    ]

    def euclidean_distance_modified(row):
        return ((row["bram"] + 1) ** 2 + row["latency"] ** 2) ** 0.5

    optimizer_data_case["modified_zero_distance"] = optimizer_data_case.apply(
        euclidean_distance_modified, axis=1
    )
    best_modified_distance = optimizer_data_case["modified_zero_distance"].min()
    best_modified_distance_row = optimizer_data_case[
        optimizer_data_case["modified_zero_distance"] == best_modified_distance
    ]

    def huristic_score(latency, bram, base_latency, base_bram, ALPHA=0.4):
        relative_latency = latency / base_latency
        relative_bram = bram / base_bram
        score = ALPHA * relative_latency + (1 - ALPHA) * relative_bram
        return score

    optimizer_data_case["heuristic_score"] = optimizer_data_case.apply(
        lambda row: huristic_score(
            row["latency"],
            row["bram"],
            baseline_latency,
            baseline_bram,
        ),
        axis=1,
    )

    best_heuristic_score = optimizer_data_case["heuristic_score"].min()
    best_heuristic_score_row = optimizer_data_case[
        optimizer_data_case["heuristic_score"] == best_heuristic_score
    ]
    baseline_heuristic_score = huristic_score(
        baseline_latency,
        baseline_bram,
        baseline_latency,
        baseline_bram,
    )

    improvement_product = baseline_modified_product / best_modified_product
    improvement_distance = baseline_modified_distance / best_modified_distance
    improvement_heuristic = baseline_heuristic_score / best_heuristic_score

    df_points_for_this_design_all_optimizers = df_points[
        df_points["design_name"] == design
    ].copy()

    ref_y = df_points_for_this_design_all_optimizers["latency"].max() * 1.1
    ref_x = baseline_bram * 1.1
    ref_point = (ref_x, ref_y)
    vol, _points = compute_hypervolume(
        ref_point,
        optimizer_data_case["bram"].to_list(),
        optimizer_data_case["latency"].to_list(),
    )

    best_pareto_solution[(design, optimizer)] = {
        "modified_product": {
            "bram": best_modified_product_row["bram"].values[0].item(),
            "latency": best_modified_product_row["latency"].values[0].item(),
            "metric_val": best_modified_product,
            "baseline_improvement": improvement_product,
        },
        "modified_distance": {
            "bram": best_modified_distance_row["bram"].values[0].item(),
            "latency": best_modified_distance_row["latency"].values[0].item(),
            "metric_val": best_modified_distance,
            "baseline_improvement": improvement_distance,
        },
        "heuristic_score": {
            "bram": best_heuristic_score_row["bram"].values[0].item(),
            "latency": best_heuristic_score_row["latency"].values[0].item(),
            "metric_val": best_heuristic_score,
            "baseline_improvement": improvement_heuristic,
        },
    }

    improvement_row = {
        "design_name": design,
        "optimizer_name": optimizer,
        "improvement_product": improvement_product,
        "improvement_distance": improvement_distance,
        "best_modified_product": best_modified_product,
        "improvement_heuristic": improvement_heuristic,
    }

    data_improvement.append(improvement_row)

    hypervolume_row = {
        "design_name": design,
        "optimizer_name": optimizer,
        "hypervolume": vol,
    }
    data_hypervolume.append(hypervolume_row)

df_improvement = pd.DataFrame(data_improvement)
df_hypervolume = pd.DataFrame(data_hypervolume)


df_improvement_pivot = df_improvement.pivot(
    index="design_name", columns="optimizer_name", values="improvement_heuristic"
)
df_improvement_pivot_for_latex = df_improvement_pivot.copy()
df_improvement_pivot_for_latex = df_improvement_pivot_for_latex.rename(
    columns=optimizer_to_name_map
)
# df_improvement_pivot_for_latex = df_improvement_pivot_for_latex[
#     [
#         "Random Search",
#         "Group Random Search",
#         "Heuristic",
#         "Init Simulated Annealing",
#     ]
# ]
df_improvement_pivot_for_latex = df_improvement_pivot_for_latex.reset_index()
df_improvement_pivot_for_latex = df_improvement_pivot_for_latex.rename(
    columns={"design_name": "Design Name"}
)

txt_latex = df_improvement_pivot_for_latex.to_latex(
    index=False,
    float_format="%.2fx",
    column_format="l" + "c" * len(df_improvement_pivot_for_latex.columns),
    escape=True,
    label="tab:improvement",
    caption="Improvement of the best solution found by each optimizer over the baseline. The improvement is calculated as the ratio of the baseline modified product to the best modified product found by each optimizer. The modified product is defined as (bram + 1) * latency.",
    position="th",
)

with open(DIR_DATA / "tab_improvement.tex", "w") as f:
    f.write(txt_latex)

optimizers_to_plot = [
    "heuristic",
    "random_search",
    "discrete_simulated_annealing",
    "group_random_search",
    "grouped_discrete_simulated_annealing",
]


improvement_plot_data = []
for (design, optimizer), data in best_pareto_solution.items():
    baseline_row = df_baseline[df_baseline["design_name"] == design].copy()
    assert len(baseline_row) == 1
    improvement_plot_data.append(
        {
            "design_name": design,
            "optimizer_name": optimizer,
            "bram": data["heuristic_score"]["bram"],
            "latency": data["heuristic_score"]["latency"],
            "slowdown": data["heuristic_score"]["latency"]
            / baseline_row["latency"].values[0].item(),
            "relative_bram_usage": (
                data["heuristic_score"]["bram"] / baseline_row["bram"].values[0].item()
            ),
        }
    )
df_improvement_plot = pd.DataFrame(improvement_plot_data)
# if optimizer_name is not in optimizers_to_plot remove it
df_improvement_plot = df_improvement_plot[
    df_improvement_plot["optimizer_name"].isin(optimizers_to_plot)
]

print(df_improvement_plot)

fig, axs = plt.subplots(2, 1, figsize=(12, 8))

ax_bram: Axes = axs[0]
ax_latency: Axes = axs[1]

# first axs is for the bram reduction
ax_bram.grid(which="both", linestyle="--", linewidth=0.5)
ax_bram.set_axisbelow(True)

sns.barplot(
    data=df_improvement_plot,
    x="design_name",
    y="relative_bram_usage",
    hue="optimizer_name",
    hue_order=optimizers_to_plot,
    palette=optimizer_to_color_map.values(),
    ax=ax_bram,
)

from matplotlib.patches import Rectangle

for i, bar in enumerate(ax_bram.patches):
    if isinstance(bar, Rectangle) and bar.get_height() < 0.05:
        ax_bram.text(
            bar.get_x() + bar.get_width() / 2,
            bar.get_height() + 0.01,
            "x",
            ha="center",
            va="bottom",
            color="red",
        )

ax_bram.set_ylim(0, 1.1)

ax_bram.set_yticks(np.arange(0, 1.1, 0.1))
ax_bram.set_yticklabels(
    [f"{int(x * 100)}%" for x in np.arange(0, 1.1, 0.1)],
    # fontsize=8,
)

ax_bram.set_title("Relative FIFO BRAM Usage Compared to Baseline Design")
ax_bram.set_ylabel("Relative FIFO BRAM Usage")


ax_latency.grid(which="both", linestyle="--", linewidth=0.5)
ax_latency.set_axisbelow(True)

sns.barplot(
    data=df_improvement_plot,
    x="design_name",
    y="slowdown",
    hue="optimizer_name",
    hue_order=optimizers_to_plot,
    palette=optimizer_to_color_map.values(),
    ax=ax_latency,
)
ax_latency.set_ylim(0.5, top=5)
ax_latency.set_yticks(np.arange(0.5, 5.1, 0.5))
# ax_latency.set_yticklabels(

ax_bram.set_title("Relative Latency Slowdown Compared to Baseline Design")
ax_bram.set_ylabel("Relative Latency Slowdown Usage")


fig.tight_layout()
fig.savefig(DIR_FIGURES / "__baseline_comparison.png", dpi=300)

exit()

################################################

df_hypervolume_pivot = df_hypervolume.pivot(
    index="design_name", columns="optimizer_name", values="hypervolume"
)

df_hypervolume_pivot = df_hypervolume_pivot.div(
    df_hypervolume_pivot["random_search"], axis=0
)


# df_hypervolume_pivot = df_hypervolume_pivot[
#     [
#         "random_search",
#         "group_random_search",
#         "heuristic",
#     ]
# ]


def geo_mean(iterable):
    a = np.array(iterable)
    return a.prod() ** (1.0 / len(a))


# compute the geomean for each colum
geomeans = {}
for col in df_hypervolume_pivot.columns:
    geomeans[col] = geo_mean(df_hypervolume_pivot[col])

df_hypervolume_pivot_for_latex = df_hypervolume_pivot.copy()
df_hypervolume_pivot_for_latex = df_hypervolume_pivot_for_latex.rename(
    columns=optimizer_to_name_map
)

df_hypervolume_pivot_for_latex = df_hypervolume_pivot_for_latex.reset_index()
df_hypervolume_pivot_for_latex = df_hypervolume_pivot_for_latex.rename(
    columns={"design_name": "Design Name"}
)
txt_latex = df_hypervolume_pivot_for_latex.to_latex(
    index=False,
    float_format="%.2fx",
    column_format="l|" + "c" * len(df_hypervolume_pivot_for_latex.columns),
    escape=True,
    label="tab:hypervolume",
    caption='Relative hypervolume of the pareto front found by each optimizer relative to the baseline "Random Search" optimizer for all designs. '
    "The higher the hypervolume the better the discovered pareto front. "
    "The reference point used for the hypervolume calculation is $(1.1*\\text{bram}_\\text{baseline}, 1.1*\\text{latency}_\\text{max})$, where $\\text{bram}_\\text{baseline}$ is the BRAM usage of the baseline design and $\\text{latency}_\\text{max}$ is the maximum latency of all designs.",
    position="th",
)

# create a new row with the geomeans
row_geomean_txt = ""
row_geomean_txt += "Geomean & "
print(geomeans)
for col in df_hypervolume_pivot.columns[:]:
    print(f"{col}: {geomeans[col]:.2f}x")
    row_geomean_txt += f"{geomeans[col]:.2f}x & "
row_geomean_txt += "\\\\\n"


txt_latex = txt_latex.replace(
    "\\bottomrule", "\\hline\n" + row_geomean_txt + "\\bottomrule\n"
)

(DIR_DATA / "tab_hypervolume.tex").write_text(txt_latex)


# plot frontiers per solution space
def plot_design(design):
    # plot the baseline
    baseline_data_case = df_baseline[(df_baseline["design_name"] == design)].copy()
    assert len(baseline_data_case) == 1
    baseline_bram = baseline_data_case["bram"].values[0].item()
    baseline_latency = baseline_data_case["latency"].values[0].item()

    df_points_for_this_design = df_points[df_points["design_name"] == design].copy()

    fig, ax = plt.subplots(figsize=(8, 8))

    ax.grid(which="both", linestyle="--", linewidth=0.5)
    ax.set_axisbelow(True)

    for optimizer in optimizers:
        optimizer_data_case = df_points[
            (df_points["design_name"] == design)
            & (df_points["optimizer_name"] == optimizer)
        ].copy()

        optimizer_data_case = optimizer_data_case.sort_values(
            ["latency", "bram"], ascending=[False, True]
        )
        bram_vals = optimizer_data_case["bram"].tolist()
        latency_vals = optimizer_data_case["latency"].tolist()

        # plot the points
        ax.plot(
            bram_vals,
            latency_vals,
            marker="o",
            linestyle="--",
            markersize=10,
            label=optimizer,
            color=optimizer_to_color_map[optimizer],
        )

        # plot the best product point
        metric = "heuristic_score"
        best_point = best_pareto_solution[(design, optimizer)]
        best_bram = best_point[metric]["bram"]
        best_latency = best_point[metric]["latency"]

        ax.plot(
            best_bram,
            best_latency,
            marker="x",
            markersize=20,
            linewidth=12,
            linestyle=None,
            color=optimizer_to_color_map[optimizer],
        )

        max_y = df_points_for_this_design["latency"].max() * 1.1
        max_x = baseline_bram * 1.1

        vol, points = compute_hypervolume(
            (max_x, max_y),
            bram_vals,
            latency_vals,
        )
        print(f"hypervolume for {optimizer} {design}: {vol}")
        poly_x, poly_y = zip(*points)
        ax.fill(
            poly_x,
            poly_y,
            alpha=0.05,
            color=optimizer_to_color_map[optimizer],
            # label=f"{optimizer} HV: {vol:.2f}",
        )

    ax.plot(
        baseline_bram,
        baseline_latency,
        marker="*",
        markersize=20,
        linestyle=None,
        label="baseline",
        color="green",
    )

    ax.set_xlim(0, max_x)
    ax.set_ylim(0, max_y)

    ax.set_xlabel("BRAM usage")
    ax.set_ylabel("Latency")
    ax.set_title("Latency vs BRAM usage")
    ax.legend(fontsize=8)

    return fig


# for design in designs:
#     fig = plot_design(design)
#     fig.savefig(DIR_FIGURES / f"{design}.png", dpi=300)
#     plt.close(fig)


def parallel_fn_plot_design(design):
    fig = plot_design(design)
    fig.savefig(DIR_FIGURES / f"{design}.png", dpi=300)
    plt.close(fig)


N_JOBS = 32
with multiprocessing.Pool(N_JOBS) as pool:
    figs = pool.map(parallel_fn_plot_design, designs)
