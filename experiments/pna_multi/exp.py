from concurrent.futures import ThreadPoolExecutor
from functools import partial
from pathlib import Path

from fifo_advisor.automation import TestCase
from fifo_advisor.opt_env import LSEnv, MultiFIFOOptimizer
from fifo_advisor.solvers import (
    DiscreteSimulatedAnnealingOptimizer,
    GroupedDiscreteSimulatedAnnealingOptimizer,
    GroupRandomSearchOptimizer,
    HeuristicOptimizer,
    MultiDiscreteSimulatedAnnealingOptimizer,
    MultiGroupRandomSearchOptimizer,
    MultiHeuristicOptimizer,
    T_FIFOOptimizer,
    T_MultiFIFOOptimizer,
)

DIR_CURRENT = Path(__file__).parent

DIR_FIGURES = DIR_CURRENT / "figures"
if not DIR_FIGURES.exists():
    DIR_FIGURES.mkdir(exist_ok=True)

DIR_DATA = DIR_CURRENT / "data"
if not DIR_DATA.exists():
    DIR_DATA.mkdir(exist_ok=True)


DIR_PNA_PROJECTS = DIR_CURRENT / "pna_projects"

if not DIR_PNA_PROJECTS.exists():
    raise FileNotFoundError(
        f"PNA projects directory {DIR_PNA_PROJECTS} does not exist. Please run pre_synth.py first."
    )

project_dirs = sorted(DIR_PNA_PROJECTS.glob("*"))

test_cases = [
    TestCase.from_dir(
        dir_project,
    )
    for dir_project in project_dirs
]

test_cases = test_cases[:]  # limit to first design for faster testing

N_JOBS_OVER_ENVS = 64

optimizers: dict[str, partial[MultiFIFOOptimizer]] = {
    # "random_search": partial(
    #     RandomSearchOptimizer,
    #     n_samples=1000,
    # ),
    "multi_group_random_search": partial(
        MultiGroupRandomSearchOptimizer,
        n_samples=5000,
        n_jobs_over_envs=N_JOBS_OVER_ENVS,
    ),
    "multi_heuristic": partial(
        MultiHeuristicOptimizer,
        n_jobs_over_envs=N_JOBS_OVER_ENVS,
    ),
    # "init_simulated_annealing": partial(
    #     GroupRandomInitializedSimulatedAnnealingOptimizer,
    #     n_samples=1000,
    # ),
    "multi_discrete_simulated_annealing": partial(
        MultiDiscreteSimulatedAnnealingOptimizer,
        maxfun=5000 // 4,
        n_scaling_factors=4,
        init_with_largest=True,
        n_jobs_over_envs=N_JOBS_OVER_ENVS,
    ),
    # "grouped_discrete_simulated_annealing": partial(
    #     GroupedDiscreteSimulatedAnnealingOptimizer,
    #     maxfun=5000 // 4,
    #     n_scaling_factors=4,
    #     init_with_largest=True,
    # ),
}


def run_single_eval(design_cases: list[TestCase], optimizer_name: str):
    print(
        f"Running design cases as single design for multi optimizer\n{design_cases}\nwith optimizer\n{optimizer_name}"
    )

    prj_paths = [design.prj_path.resolve().absolute() for design in design_cases]

    sim_envs = [
        LSEnv(
            design.solution_dir,
        )
        for design in design_cases
    ]

    optimizer_class = optimizers[optimizer_name]
    optimizer = optimizer_class(
        sim_envs,
    )

    try:
        results = optimizer.solve()
    except Exception as e:
        # print(f"Error in design: {[design.name for design in design_cases]}: {e}")
        raise e
        print(e)
        return


combos = [
    # (test_cases, "multi_group_random_search"),
    # (test_cases, "multi_heuristic"),
    (test_cases, "multi_discrete_simulated_annealing"),
]

# N_JOBS = 1
# with ThreadPoolExecutor(max_workers=N_JOBS) as executor:
#     data_all = executor.map(lambda x: run_single_eval(*x), combos)

# use joblib
for combo in combos:
    run_single_eval(*combo)
