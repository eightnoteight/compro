from sys import stdin
from math import ceil, log


def main():
    class max_count(object):

        def __init__(self, arr):
            self.tree = [0]*(2*(pow(2, int(ceil(log(len(arr), 2))))) - 1)
            self._construct_tree(arr, 0, len(arr), 0)

        def _construct_tree(self, arr, lo, hi, ind):
            if hi - lo == 1:
                self.tree[ind] = arr[lo]
                return arr[lo]
            if hi - lo < 1:
                return float('inf')
            mid = (lo + hi) // 2
            self.tree[ind] = min(
                self._construct_tree(arr, lo, mid, 2*ind + 1),
                self._construct_tree(arr, mid, hi, 2*ind + 2))

        def count(self, Q, lo, hi, qlo, qhi, ind):
            if (hi - lo < 1) or (qhi - qlo < 1) or (hi <= qlo) or (lo >= qhi):
                return 0
            if hi - lo == 1:
                if self.tree[ind] > Q:
                    return 1
                return 0
            mid = (lo + hi) // 2
            if qlo < mid < qhi:
                if self.tree[ind] > Q:
                    return qhi - qlo
                return self.count(Q, lo, mid, qlo, mid, 2*ind + 1) + self.count(Q, mid, hi, mid, qhi, 2*ind + 2)
            if qlo < qhi <= mid:
                return self.count(Q, lo, mid, qlo, qhi, 2*ind + 1)
            if mid <= qlo < qhi:
                return self.count(Q, mid, hi, qlo, qhi, 2*ind + 2)
    raw_input = stdin.readline
    raw_input()
    arr = map(int, raw_input().split())
    rmc = max_count(arr)
    for x in xrange(int(raw_input())):
        i, j, k = map(int, raw_input().split())
        print rmc.count(k, 0, len(arr), i - 1, j, 0)

main()
