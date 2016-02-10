from sys import stdin

def bsearch(lo, hi, check):
    while lo < hi:
        mid = lo + ((hi - lo) // 2)
        if check(mid):
            hi = mid
        else:
            lo = mid + 1
    return lo

def minOutputRate(tx, inrates, cap):
    def feasibility(orate):
        orate /= 10000000000.
        tank = 0
        for ir, txe in zip(inrates, tx):
            totwater = tank + ir * txe
            tank = max(totwater - orate * txe, 0)
            if tank > cap:
                return False
        return True
    return bsearch(0, 10**32, feasibility) / 10000000000. - 1e-10


def main():
    nextint = map(int, stdin.read().split()).__next__
    n = nextint()
    times = [nextint() for _ in range(n)]
    irates = [nextint() for _ in range(n)]
    cap = nextint()
    print(minOutputRate(times, irates, cap))

main()
