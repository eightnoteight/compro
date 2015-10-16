from math import ceil, log


def main():
    class RangeSum(object):
        def __init__(self, n):
            self.tree = [0] * (2 * (1 << int(ceil(log(n, 2)))) + 1)

        def add(self, lo, hi, posval, ind):
            # if hi - lo < 1 or posval[0] < lo or posval[0] >= hi:
            #     print "test"
            #     return
            if hi - lo == 1:
                self.tree[ind] += posval[1]
                return
            mid = (hi + lo) // 2
            # print("add", lo, mid, hi, posval)
            if posval[0] < mid:
                self.tree[ind] += posval[1]
                self.add(lo, mid, posval, 2 * ind + 1)
            else:
                self.tree[ind] += posval[1]
                self.add(mid, hi, posval, 2 * ind + 2)

        def find(self, lo, hi, qlo, qhi, ind):
            if qhi <= lo or qlo >= hi:
                return 0
            mid = (hi + lo) // 2
            # print("find", lo, mid, hi, qlo, qhi)
            if qlo <= lo < hi <= qhi:
                return self.tree[ind]
            elif qlo < qhi <= mid:
                return self.find(lo, mid, qlo, qhi, 2 * ind + 1)
            elif mid <= qlo < qhi:
                return self.find(mid, hi, qlo, qhi, 2 * ind + 2)
            elif qlo < mid < qhi:
                return self.find(lo, mid, qlo, mid, 2 * ind + 1) + \
                    self.find(mid, hi, mid, qhi, 2 * ind + 2)

    n, q = map(int, raw_input().split())
    rsum = RangeSum(n)
    for x in xrange(q):
        c, a, b = raw_input().split()
        if c[0] == 'f':
            print(rsum.find(0, n, int(a) - 1, int(b), 0))
            # print(rsum.tree)
        else:
            rsum.add(0, n, (int(a) - 1, int(b)), 0)
            # print(rsum.tree)

main()
