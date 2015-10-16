from sys import stdin
import numpy as np
n, k = map(int, stdin.readline().split())
print (n - len(np.nonzero(np.loadtxt(stdin, dtype=np.int64) % k)[0]))
