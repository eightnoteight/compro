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
    ids = [nextint() for _ in xrange(n)]
    i = bsearch(1, n + 1, lambda x: ((x * (x + 1)) // 2) >= k)
    print ids[k - ((i * (i - 1)) // 2) - 1]

main()
