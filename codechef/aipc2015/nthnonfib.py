from sys import stdin

def bsearch(lo, hi, check):
    while lo < hi:
        mid = lo + ((hi - lo) // 2)
        if check(mid):
            hi = mid
        else:
            lo = mid + 1
    return lo

def main():
    nfibs = [0, 1, 2]
    nfibs_starts = [0, 4, 6]
    for _ in xrange(100):
        nfibs.append(nfibs[-1] + nfibs[-2] + 1)
        nfibs_starts.append(nfibs_starts[-1] + nfibs[-2] + 1)
    for x in xrange(1, len(nfibs)):
        nfibs[x] += nfibs[x - 1]
    nextint = iter(map(int, stdin.read().split())).next
    for _ in xrange(nextint()):
        n = nextint()
        check = lambda x: nfibs[x] >= n
        print nfibs_starts[bsearch(0, 100, check)] + n - nfibs[bsearch(0, 100, check) - 1] - 1
main()
