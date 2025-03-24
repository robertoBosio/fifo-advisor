import shutil
from pathlib import Path
from pprint import pp
from tempfile import TemporaryDirectory

import numpy as np
from dotenv import dotenv_values
from joblib import Parallel, delayed
from matplotlib import pyplot as plt

from fifo_opt.automation import TestCase
from fifo_opt.opt_env import LSEnv

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


pp(list(map(lambda x: x.dir.name, designs_all)))


def run_single(design: TestCase) -> None:
    print(f"Running design: {design.dir}")
    prj_path = design.prj_path.resolve().absolute()

    _sim_env = LSEnv(
        design.solution_dir,
        env_vars_extra={
            "PRJ_PATH": str(prj_path),
        },
    )


N_JOBS = 48

Parallel(n_jobs=N_JOBS, backend="multiprocessing")(
    delayed(run_single)(design) for design in designs_all
)
