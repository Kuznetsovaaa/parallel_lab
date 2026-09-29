import numpy as np

def load(name):
    f = open(name, "r")
    n = int(f.readline())
    m = []
    for i in range(n):
        m.append([float(x) for x in f.readline().split()])
    f.close()
    return np.array(m)

A = load("A.txt")
B = load("B.txt")
C = load("C.txt")

expected = A @ B
diff = np.max(np.abs(C - expected)) / np.max(np.abs(expected))

print(f"Relative difference: {diff:.3e}")
if diff < 1e-8:
    print("Verification passed")
else:
    print("Verification failed")