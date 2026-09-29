import numpy as np
import sys

n = int(sys.argv[1]) if len(sys.argv) > 1 else 200

rng = np.random.default_rng(42)
A = rng.uniform(-10, 10, (n, n))
B = rng.uniform(-10, 10, (n, n))

def save(name, m):
    with open(name, "w") as f:
        f.write(str(n) + "\n")
        for row in m:
            f.write(" ".join(f"{x:.15f}" for x in row) + "\n")

save("A.txt", A)
save("B.txt", B)

print(f"Generated A.txt and B.txt with size {n}x{n}")