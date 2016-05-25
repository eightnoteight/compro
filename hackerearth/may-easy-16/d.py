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
    nextint = iter(map(int, stdin.read().split())).next
    n, k = nextint(), nextint()
    arra = [nextint() for _ in xrange(n)]
    arrb = [nextint() for _ in xrange(n)]
    def checkf(x):
        return sum([max(arra[i] * x - arrb[i], 0) for i in xrange(n)]) > k
    print bsearch(0, 2000000002, checkf) - 1

main()
