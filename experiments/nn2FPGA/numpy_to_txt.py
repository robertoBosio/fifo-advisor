import numpy as np
import sys

data = np.load(sys.argv[1])
flat = data.flatten()

with open(sys.argv[2], "w") as f:
    for v in flat:
        f.write(f"{v}\n")
