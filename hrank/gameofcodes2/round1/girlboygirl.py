from itertools import groupby

from sys import stdin

dstream = iter(stdin.read().split())

for _ in xrange(int(next(dstream))):
    w = next(dstream)
    print len(w) - len(list(groupby(w)))
