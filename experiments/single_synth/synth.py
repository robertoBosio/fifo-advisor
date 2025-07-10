import shutil
from pathlib import Path

from fifo_opt.automation import TestCase

DIR_CURRENT = Path(__file__).parent
DIR_ROOT = DIR_CURRENT.parent.parent
# DIR_TEST_CASES = DIR_ROOT / "test_cases"
# DIR_TEST_CASES = DIR_ROOT / "test_cases_inr"
# DIR_TEST_CASES = DIR_ROOT / "test_cases_soda"
# DIR_TEST_CASES = DIR_ROOT / "test_cases_autosa"
# DIR_TEST_CASES = DIR_ROOT / "test_cases_streamhls_large"
DIR_TEST_CASES = DIR_ROOT / "test_cases_synthetic"


design_to_test = "scatter_gather"

test_case_dir = DIR_TEST_CASES / design_to_test
assert test_case_dir.exists(), f"Test case dir {test_case_dir} does not exist"
print(f"Test case dir: {test_case_dir}")

local_test_case_dir = DIR_CURRENT / "test_cases" / design_to_test
local_test_case_dir.mkdir(parents=True, exist_ok=True)

test_case = TestCase.from_dir(test_case_dir, design_to_test.split("__")[0])
test_case.copy_to(dest=local_test_case_dir)

# test_case.run_csim()
test_case.run_synth()
# test_case.run_cosim()
