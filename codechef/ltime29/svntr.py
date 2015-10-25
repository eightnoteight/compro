from sys import stdin
from itertools import combinations


def bsearch(lo, hi, check):
    while lo < hi:
        mid = lo + (hi - lo) // 2
        if check(mid):
            hi = mid
        else:
            lo = mid + 1
    return lo

def main():
    nextint = iter(map(int, stdin.read().split())).next
    for _ in xrange(nextint()):
        n, m, s = nextint(), nextint(), nextint()
        mat = [[0]*(m + 1) for _ in xrange(n + 1)]
        for x in xrange(1, n + 1):
            for y in xrange(1, m + 1):
                mat[x][y] = nextint() + mat[x - 1][y] + mat[x][y - 1] - mat[x - 1][y - 1]
        cnt = 0
        diffarrs = {}
        for x, y in combinations(xrange(n + 1), 2):
            diffarrs[(x, y)] = sorted([mat[y][z] - mat[x][z] for z in xrange(m + 1)])

        for x1 in xrange(n + 1):
            for y1 in xrange(m + 1):
                for x2 in xrange(x1 + 1, n + 1):
                    arr = diffarrs[(x1, x2)]
                    k = s - mat[x1][y1] + mat[x2][y1]
                    cnt += bsearch(0, len(arr), lambda x: arr[x] > k)
                    # for y2 in xrange(y1 + 1, m + 1):
                    #     if mat[x2][y2] + mat[x1][y1] - mat[x2][y1] - mat[x1][y2] <= s:
                    #         cnt += 1

        print cnt

main()
