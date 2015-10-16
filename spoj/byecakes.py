from math import ceil
from sys import stdin

def main():
    inp = map(float, stdin.read().split())
    for x in xrange(len(inp) // 8 - 1):
        n = max(
            ceil(inp[8*x]/inp[8*x + 4]),
            ceil(inp[8*x + 1]/inp[8*x + 5]),
            ceil(inp[8*x + 2]/inp[8*x + 6]),
            ceil(inp[8*x + 3]/inp[8*x + 7]))
        print "%d %d %d %d" % (n*inp[8*x + 4] - inp[8*x], n*inp[8*x + 5] - inp[8*x + 1], n*inp[8*x + 6] - inp[8*x + 2], n*inp[8*x + 7] - inp[8*x + 3])

main()
