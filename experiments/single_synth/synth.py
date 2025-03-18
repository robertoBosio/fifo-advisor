from pathlib import Path
from fifo_opt.automation import TestCase

DIR_CURRENT = Path(__file__).parent
DIR_ROOT = DIR_CURRENT.parent.parent
DIR_TEST_CASES = DIR_ROOT / "test_cases"

design_to_test = "atax__opt5"

test_case_dir = DIR_TEST_CASES / design_to_test
print(f"Test case dir: {test_case_dir}")

local_test_case_dir = DIR_CURRENT / "test_cases" / design_to_test
local_test_case_dir.mkdir(parents=True, exist_ok=True)

test_case = TestCase.from_dir(test_case_dir, design_to_test)
test_case.copy_to(local_test_case_dir)

