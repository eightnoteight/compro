from sys import stdin
from collections import defaultdict

def main():
    nextint = iter(map(int, stdin.read().split())).next
    pts = [(nextint(), nextint()) for _ in xrange(nextint())]
    xpts, ypts = defaultdict(int), defaultdict(int)
    com = defaultdict(int)
    for x, y in pts:
        xpts[x] += 1
        ypts[y] += 1
        com[(x, y)] += 1
    ans = 0
    for v in xpts.values():
        ans += v * (v - 1) // 2
    for v in ypts.values():
        ans += v * (v - 1) // 2
    for v in com.values():
        ans -= v * (v - 1) // 2
    print ans

main()


# 00:31 1314
