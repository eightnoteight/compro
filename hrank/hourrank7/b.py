from sys import stdin


def bsearch(lo, hi, check):
    while lo < hi:
        mid = lo + ((hi - lo) // 2)
        if check(mid):
            hi = mid
        else:
            lo = mid + 1
    return lo

def maxscore(arr, lo, hi):
    if hi <= lo or hi - lo < 2:
        return 0
    if hi - lo == 2:
        return arr[hi] - arr[lo + 1] == arr[lo + 1] - arr[lo]
    ts = arr[hi] - arr[lo]
    if ts % 2 != 0:
        return 0
    req = arr[lo] + (ts // 2)
    k = bsearch(lo, hi, lambda x: arr[x] >= req)
    if k < hi and arr[k] == req:
        return max(maxscore(arr, lo, k), maxscore(arr, k, hi)) + 1
    return 0

def main():
    nextint = iter(map(int, stdin.read().split())).next
    for _ in xrange(nextint()):
        n = nextint()
        arr = [nextint() for _ in xrange(n)]
        print int(maxscore(arr))

main()
