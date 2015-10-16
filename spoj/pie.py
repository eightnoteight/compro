from sys import stdin
from math import pi

def bisect_left(a, x, lo=0, hi=None):
    if lo < 0:
        raise ValueError('lo must be non-negative')
    if hi is None:
        hi = len(a)
    while lo < hi:
        mid = (lo+hi)//2
        if a[mid] < x: lo = mid+1
        else: hi = mid
    return lo

class bsearch_util:
    def __init__(self, n, f, vols):
        self.n = n
        self.f = f
        self.vols = vols

    def __getitem__(self, x):
        # print "[v / x for v in self.vols] = ", [v / x for v in self.vols]
        x /= 100000.
        return sum(map(int, [v / x for v in self.vols])) < self.f




def main():
    dstream = iter(map(int, stdin.read().split()))
    for _ in xrange(next(dstream)):
        n, f = next(dstream), next(dstream)
        vols = [pi*(next(dstream)**2) for _ in xrange(n)]
        ourds = bsearch_util(n, f + 1, vols)
        # print [ourds[x] for x in xrange(1, 60)]
        print "%.4f" % ((bisect_left(ourds, True, 1, 100000000000001) - 1) / 100000.)


main()
