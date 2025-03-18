from pathlib import Path
from dataclasses import dataclass
import shutil

def auto_find_vitis_hls():
    raise NotImplementedError

def auto_find_vivado():
    raise NotImplementedError

class TestCase:
    def __init__(self, dir: Path, name: str):
        self.dir = dir
        self.name = name

    @classmethod
    def from_dir(cls, dir: Path, name: str | None = None):
        if name is None:
            name = dir.name
        return cls(dir, name)

    def copy_to(self, dest: Path):
        shutil.copytree(self.dir, dest, dirs_exist_ok=True)

    def run_csim(self):
        raise NotImplementedError

    def run_csynth(self):
        raise NotImplementedError

    def run_cosim(self):
        raise NotImplementedError
    
    def run_lightning_sim(self):
        raise NotImplementedError
