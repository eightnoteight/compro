from sys import stdin
from itertools import groupby
from operator import itemgetter
from functools import partial

nextint = iter(stdin.read().split()).next
palins = [
    [], ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9'],
    ['00', '11', '22', '33', '44', '55', '66', '77', '88', '99']]
for x in xrange(3, 12):
    palins.append([z + y + z for z in '0123456789' for y in palins[x - 2]])
tot = []
for x in xrange(12):
    tot.extend(palins[x])
tot = map(itemgetter(0), groupby(sorted([int(x) for x in tot if str(int(x)) == str(int(x))[::-1]])))
diffs = [(0, 0)]
for x in xrange(1, len(tot)):
    if tot[x] - tot[x - 1] > 1:
        diffs.append((tot[x - 1] + 1, diffs[-1][1] + tot[x] - tot[x - 1] - 1))

def bsearch(lo, hi, check):
    while lo < hi:
        mid = lo + (hi - lo) // 2
        if check(mid):
            hi = mid
        else:
            lo = mid + 1
    return lo

def _check(nn, kk):
    return diffs[kk][1] >= nn

for _ in xrange(int(nextint())):
    n = int(nextint())
    if n == 0:
        print 1
    else:
        idx = bsearch(0, len(diffs), partial(_check, n))
        print diffs[idx][0] + n - diffs[idx - 1][1] - 1

