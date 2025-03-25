import itertools
from pathlib import Path

import matplotlib.pyplot as plt
import pandas as pd

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


designs = df_baseline["design_name"].unique().tolist()
optimizers = df_points["optimizer_name"].unique().tolist()

all_cases = itertools.product(designs, optimizers)

# for each design and optmizer find the lowest latency bram product and compute the speed up oevr the baseline
data_improvement = []
for design, optimizer in all_cases:
    baseline_data_case = df_baseline[(df_baseline["design_name"] == design)].copy()
    assert len(baseline_data_case) == 1

    optimizer_data_case = df_points[
        (df_points["design_name"] == design)
        & (df_points["optimizer_name"] == optimizer)
    ].copy()
    # find the point closest to (0, 0) for bram latency using euclidean distance
    optimizer_data_case["euclidean_distance"] = (
        optimizer_data_case["bram"] ** 2 + optimizer_data_case["latency"] ** 2
    ) ** 0.5
    #
    min_point = optimizer_data_case["euclidean_distance"].min()
    min_point_row = optimizer_data_case[
        optimizer_data_case["euclidean_distance"] == min_point
    ]

    min_point_product = min_point_row["latency_bram_product"].values[0].item()
    baseline_product = baseline_data_case["latency_bram_product"].values[0].item()

    improvement = baseline_product / min_point_product

    improvement_row = {
        "design_name": design,
        "optimizer_name": optimizer,
        "improvement": improvement,
    }

    data_improvement.append(improvement_row)
df_improvement = pd.DataFrame(data_improvement)
print(df_improvement)
