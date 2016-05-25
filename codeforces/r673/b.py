from operator import itemgetter
from sys import stdin


def main():
    nextint = iter(map(int, stdin.read().split())).next
    n, m = nextint(), nextint()
    if m == 0:
        print n - 1
        return
    edges = []
    for _ in xrange(m):
        edges.append((nextint() - 1, nextint() - 1))
        if edges[-1][0] > edges[-1][1]:
            edges[-1] = (edges[-1][1], edges[-1][0])
    l1, l2 = sorted(map(itemgetter(0), edges)), sorted(map(itemgetter(1), edges))
    if l2[0] <= l1[-1]:
        print 0
        return
    print 2**(l2[0] - l1[-1] - 1)


main()
