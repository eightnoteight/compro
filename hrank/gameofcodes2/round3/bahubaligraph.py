from sys import stdin
from operator import itemgetter
from itertools import groupby

def main():
    dstream = iter(stdin.read().split())
    nextint = lambda: int(next(dstream))
    n, m = nextint(), nextint()
    edges = []
    for _ in xrange(m):
        x, y = nextint(), nextint()
        edges.append((min(x, y), max(x, y)))
    cycles = [0]*(n + 1)
    for v, ved in groupby(sorted(edges, key=itemgetter(1)), keyfunc=itemgetter(1)):
        ved = list(ved)

main()
