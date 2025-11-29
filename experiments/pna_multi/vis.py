from pathlib import Path

import matplotlib
import numpy as np

matplotlib.use("Agg")
import matplotlib.pyplot as plt
import pandas as pd

DIR_CURRENT = Path(__file__).parent

DIR_FIGURES = DIR_CURRENT / "figures"
if not DIR_FIGURES.exists():
    DIR_FIGURES.mkdir(exist_ok=True)

DIR_DATA = DIR_CURRENT / "data"
if not DIR_DATA.exists():
    DIR_DATA.mkdir(exist_ok=True)


df_data_all = pd.read_csv(DIR_DATA / "data_multi_eval_pna.csv")


df_data_all["design_index"] = df_data_all["design"].apply(
    lambda x: int(x.split("__")[-1])
)

print(df_data_all.head())


optmizer_to_keep = "grouped_discrete_simulated_annealing"

df_single = df_data_all[df_data_all["optimizer_name"] == optmizer_to_keep].copy()


# are there eval_indexe values where all design indexes have deadlock == False
good_eval_indices = []
eval_indices = df_single["eval_index"].unique()
for eval_index in eval_indices:
    df_eval = df_single[df_single["eval_index"] == eval_index]
    if not df_eval["deadlock"].any():
        print(f"Found eval_index {eval_index} where all designs have no deadlock.")
        good_eval_indices.append(eval_index)
# i.e. for ALL i in

df_filtered = df_single[df_single["eval_index"].isin(good_eval_indices)]
# df_not_aligned = df_single[~df_single["eval_index"].isin(good_eval_indices)]

# aggregate by eval_id (across designs), take max bram and latency
df_agg = (
    df_filtered.groupby("eval_index")
    .agg({"bram": "mean", "latency": "mean"})
    .reset_index()
)

print(df_agg.head())


df_by_design = {
    design_name: df_design for design_name, df_design in df_filtered.groupby("design")
}

# df_by_design_not_aligned = {
#     design_name: df_design
#     for design_name, df_design in df_not_aligned.groupby("design")
# }


fig, ax = plt.subplots(
    1,
    1,
    figsize=(8, 8),
)


def is_pareto_efficient_simple(costs):
    """
    Find the pareto-efficient points
    :param costs: An (n_points, n_costs) array
    :return: A (n_points, ) boolean array, indicating whether each point is Pareto efficient
    """
    is_efficient = np.ones(costs.shape[0], dtype=bool)
    for i, c in enumerate(costs):
        if is_efficient[i]:
            is_efficient[is_efficient] = np.any(
                costs[is_efficient] < c, axis=1
            )  # Keep any point with a lower cost
            is_efficient[i] = True  # And keep self
    return is_efficient


for design_name, df_design in df_by_design.items():
    df_design = df_design[~df_design["deadlock"]]

    costs = df_design[["bram", "latency"]].to_numpy()
    is_efficient = is_pareto_efficient_simple(costs)
    df_pareto = df_design[is_efficient]
    ax.plot(
        df_pareto["bram"],
        df_pareto["latency"],
        marker="x",
        linestyle="-",
        # label=design_name,
        color="blue",
        alpha=0.2,
    )
    # df_non_pareto = df_design[~is_efficient]
    # ax.scatter(
    #     df_non_pareto["bram"],
    #     df_non_pareto["latency"],
    #     marker="x",
    #     color="gray",
    #     alpha=0.5,
    # )

costs_agg = df_agg[["bram", "latency"]].to_numpy()
is_efficient_agg = is_pareto_efficient_simple(costs_agg)
df_pareto_agg = df_agg[is_efficient_agg]
ax.plot(
    df_pareto_agg["bram"],
    df_pareto_agg["latency"],
    marker="D",
    linestyle="--",
    color="green",
    label="Aggregated Pareto Front",
)


ax.set_yscale("log")

ax.set_xlabel("BRAM Usage")
ax.set_ylabel("Latency (cycles)")
ax.set_title(f"Pareto Fronts for Optimizer: {optmizer_to_keep}")
ax.legend(title="Design")
fig.tight_layout()
fig.savefig(DIR_FIGURES / "pareto_fronts_multi_eval_pna.png", dpi=300)


# is there a solution where all designs have no deadlocks
