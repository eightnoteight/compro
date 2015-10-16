from math import log, e, pi
from sys import stdin

try:
    range = xrange
    input = raw_input
except NameError:
    pass
inp = map(int, stdin.read().split())
for _ in range(inp[0]):
    n = inp[_ + 1]
    try:
        print(int((log(2*pi*n)/2.0 + n*(log(n) - log(e)))/log(10)) + 1)
    except ValueError:
        print(1)
    # print int(log(((n / e) ** n) * ((2 * pi * n) ** 0.5), 10)) + 1

