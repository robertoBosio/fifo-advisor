from pathlib import Path
from tempfile import TemporaryDirectory

from joblib import Parallel, delayed

from fifo_opt.automation import TestCase

DIR_CURRENT = Path(__file__).parent
DIR_ROOT = DIR_CURRENT.parent.parent
DIR_TEST_CASES = DIR_ROOT / "test_cases"


design_to_test = "atax__opt5"

test_case_dir = DIR_TEST_CASES / design_to_test
print(f"Test case dir: {test_case_dir}")

local_test_case_dir = DIR_CURRENT / "test_cases" / design_to_test
local_test_case_dir.mkdir(parents=True, exist_ok=True)

test_case = TestCase.from_dir(test_case_dir, design_to_test.split("__")[0])
test_case.copy_to(dest=local_test_case_dir)

test_case.run_csim()
test_case.run_synth()


# designs_to_test = sorted([d.name for d in DIR_TEST_CASES.glob("*")])
# designs_to_ignore = []

# designs_to_test = [design for design in designs_to_test if design not in designs_to_ignore]

# N_JOBS = 16

# def test_design(design_to_test):
#     with TemporaryDirectory() as temp_dir:
#         print(f"Test case: {design_to_test}")
#         print(f"Temp dir: {temp_dir}")

#         test_case_dir = Path(temp_dir) / design_to_test

#         test_case = TestCase.from_dir(DIR_TEST_CASES / design_to_test, design_to_test.split("__")[0])
#         test_case.copy_to(dest=test_case_dir)

#         test_case.run_synth()

# Parallel(n_jobs=N_JOBS, backend="threading")(delayed(test_design)(design) for design in designs_to_test)
