from sys import stdin

class segmenttree(object):
    def __init__(self, arr):
        self.arr = arr
        self.tree = [(float('-inf'), 0)]*(8*len(arr))
        for x in xrange(len(arr)):
            self.setval = arr[x]
            self.setind = x
            self.set(0, len(arr), 0)
        self.qlo = 0
        self.qhi = len(arr)

    def set(self, lo, hi, ind):
        if hi - lo == 1:
            if self.setind == lo:
                self.tree[ind] = (self.setval, 1)
            return
        mid = lo + ((hi - lo) // 2)
        if self.setind >= mid:
            self.set(mid, hi, 2*ind + 2)
        else:
            self.set(lo, mid, 2*ind + 1)
        if self.tree[2*ind + 1][0] == self.tree[2*ind + 2][0]:
            self.tree[ind] = (
                self.tree[2*ind + 1][0], 
                self.tree[2*ind + 1][1] + self.tree[2*ind + 2][1])
        elif self.tree[2*ind + 1][0] > self.tree[2*ind + 2][0]:
            self.tree[ind] = self.tree[2*ind + 1]
        else:
            self.tree[ind] = self.tree[2*ind + 2]

    def _query(self, lo, hi, ind):
        if lo >= self.qhi or hi <= self.qlo:
            return (float('-inf'), 0)
        if self.qlo <= lo and self.qhi >= hi:
            return self.tree[ind]
        mid = lo + ((hi - lo) // 2)
        left = self._query(lo, mid, 2*ind + 1)
        right = self._query(mid, hi, 2*ind + 2)
        if left[0] > right[0]:
            return left
        elif left[0] < right[0]:
            return right
        else:
            return (left[0], left[1] + right[1])

    def query(self, lo, hi):
        self.qlo = lo
        self.qhi = hi
        return self._query(0, len(self.arr), 0)



def main():
    nextint = iter(map(int, stdin.read().split())).next
    n, z = nextint(), nextint()
    arr = [nextint() for _ in xrange(n)]
    segt = segmenttree(arr)
    for _ in xrange(z):
        l, r = nextint() - 1, nextint()
        print segt.query(l, r)[1]

main()
