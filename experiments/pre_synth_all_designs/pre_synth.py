import shutil
from pathlib import Path
from tempfile import TemporaryDirectory

from dotenv import dotenv_values
from joblib import Parallel, delayed

from fifo_opt.automation import TestCase

DIR_CURRENT = Path(__file__).parent


DIR_ROOT = DIR_CURRENT.parent.parent
DIR_TEST_CASES = DIR_ROOT / "test_cases"


ENV_FILE: Path = DIR_CURRENT / ".env"
if ENV_FILE.exists():
    env_vars = dotenv_values(ENV_FILE)
else:
    raise FileNotFoundError(
        f"Environment file {ENV_FILE} not found. Please create it with the required variables."
    )
if "DIR_PRE_SYNTH" in env_vars:
    DIR_PRE_SYNTH = Path(env_vars["DIR_PRE_SYNTH"])
else:
    raise KeyError(
        "Environment variable 'DIR_PRE_SYNTH' not found in .env file. Please add it."
    )

if not DIR_PRE_SYNTH.exists():
    raise FileNotFoundError(
        f"Pre-synth directory {DIR_PRE_SYNTH} not found. Please create it."
    )

# design_to_test = "atax__opt5"

# test_case_dir = DIR_TEST_CASES / design_to_test
# print(f"Test case dir: {test_case_dir}")

# local_test_case_dir = DIR_CURRENT / "test_cases" / design_to_test
# local_test_case_dir.mkdir(parents=True, exist_ok=True)

# test_case = TestCase.from_dir(test_case_dir, design_to_test.split("__")[0])
# test_case.copy_to(dest=local_test_case_dir)

# test_case.run_synth()


designs_to_test = sorted([d.name for d in DIR_TEST_CASES.glob("*")])
designs_to_ignore = [
    "k3mm__opt2",
]

designs_to_test = [
    design for design in designs_to_test if design not in designs_to_ignore
]

N_JOBS = 8


def synth_design(design_to_test: str):
    print(f"Test case: {design_to_test}")

    test_case_dir = DIR_PRE_SYNTH / design_to_test
    if test_case_dir.exists():
        shutil.rmtree(test_case_dir)
    test_case_dir.mkdir()

    test_case = TestCase.from_dir(
        DIR_TEST_CASES / design_to_test, design_to_test.split("__")[0]
    )
    test_case.copy_to(dest=test_case_dir)

    test_case.run_csim()
    test_case.run_synth()


Parallel(n_jobs=N_JOBS, backend="threading")(
    delayed(synth_design)(design) for design in designs_to_test
)
