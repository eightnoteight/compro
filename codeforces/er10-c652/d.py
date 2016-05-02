from sys import stdin
from operator import itemgetter
from heapq import heappop, heappush


def bsearch(lo, hi, check):
    while lo < hi:
        mid = lo + ((hi - lo) // 2)
        if check(mid):
            hi = mid
        else:
            lo = mid + 1
    return lo

def main():
    nextint = iter(map(int, stdin.read().split())).next
    n = nextint()
    segments = [(nextint() - 1, nextint()) for _ in xrange(n)]
    # print segments
    nums = {x: i for i, x in enumerate(sorted(set(map(itemgetter(0), segments) + \
                                                  map(itemgetter(1), segments))))}
    segments = [(nums[x], nums[y]) for x, y in segments]
    order = segments[:]
    segments.sort()
    starts = map(itemgetter(0), segments)
    ends = map(itemgetter(1), segments)
    sqends = ends[:]
    sqn = int(len(ends)**0.5)
    for x in xrange(0, n, sqn):
        sqends[x: x + sqn] = sorted(sqends[x: x + sqn])
    out = []
    for a, b in order:
        ss = bsearch(0, len(starts), lambda x: starts[x] >= a)
        es = bsearch(0, len(starts), lambda x: starts[x] >= b)
        if es - ss <= 2 * sqn:
            out.append(len([None for x in ends[ss: es] if a <= x <= b]) - 1)
            count = len([None for x in ends[ss: es] if a <= x <= b]) - 1
        else:
            east = len([None for x in ends[ss: (ss // sqn + 1) * sqn] if a <= x <= b])
            west = len([None for x in ends[(es // sqn) * sqn: es] if a <= x <= b])
            mid = sum([
                bsearch(0, sqn, lambda x: sqends[st + x] >= b) - \
                bsearch(0, sqn, lambda x: sqends[st + x] >= a) \
                    for st in xrange((ss // sqn + 1) * sqn, (es // sqn)*sqn, sqn)])
            out.append(east + west + mid - 1)
            count = east + west + mid - 1
        print ss, es, count
    print '\n'.join(map(str, out))

main()



