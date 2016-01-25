from itertools import groupby
from operator import itemgetter
from functools import partial

def bsearch(lo, hi, check):
    while lo < hi:
        mid = lo + ((hi - lo) // 2)
        if check(mid):
            hi = mid
        else:
            lo = mid + 1
    return lo


def main():
    def mypredicate(segs, i, x):
        return segs[x][0] > i
    for test in xrange(1, int(raw_input()) + 1):
        n, g0, g1 = int(raw_input()), raw_input(), raw_input()
        g0segs, g1segs = [], []
        for v, it in groupby(enumerate(g0), itemgetter(1)):
            if v == '.':
                ind, _ = next(it)
                g0segs.append((ind, 1 + len(list(it))))
        for v, it in groupby(enumerate(g1), itemgetter(1)):
            if v == '.':
                ind, _ = next(it)
                g1segs.append((ind, 1 + len(list(it))))
        g0f, g1f = [True]*len(g0segs), [True]*len(g1segs)
        count = 0
        for ind, (i, l) in enumerate(g0segs):
            if l == 1:
                k = bsearch(0, len(g1segs), partial(mypredicate, g1segs, i))
                if k > 0 and g1segs[k - 1][0] + g1segs[k - 1][1] > i:
                    g1f[k - 1] = False
                g0f[ind] = False
                count += 1
        for ind, (i, l) in enumerate(g1segs):
            if l == 1 and g1f[ind]:
                k = bsearch(0, len(g0segs), partial(mypredicate, g0segs, i))
                if k > 0 and g0segs[k - 1][0] + g0segs[k - 1][1] > i:
                    g0f[k - 1] = False
                g1f[ind] = False
                count += 1
        print 'Case #%d: %d' % (test, count + sum(g0f) + sum(g1f))


main()
