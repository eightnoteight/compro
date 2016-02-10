
class unionfind:
    def __init__(self, n):
        self._length = n
        self._roots = list(xrange(n))
        self._weights = [1]*n

    def __str__(self):
        return str((self._roots, self._weights))

    def union(self, a, b):
        aroot = self.find(a)
        broot = self.find(b)
        if aroot != broot and self._weights[aroot] > self._weights[broot]:
            self._roots[broot] = aroot
            self._weights[aroot] += self._weights[broot]
            self._weights[broot] = 0
        elif aroot != broot:
            self._roots[aroot] = broot
            self._weights[broot] += self._weights[aroot]
            self._weights[aroot] = 0

    def connected(self, a, b):
        return self.find(a) == self.find(b)

    def find(self, a):
        while self._roots[a] != a:
            self._roots[a] = self._roots[self._roots[a]]
            a = self._roots[a]
        return a

def main():
    n, m = map(int, raw_input().split())
    uf = unionfind(m)
    arr = [map(int, raw_input().split()) for _ in xrange(n)]
    for ai, bi in arr:
        uf.union(ai - 1, bi - 1)
    counts = uf._weights[:]
    total = 0
    for ai, bi in arr:
        if counts[uf.find(ai - 1)] > 0:
            counts[uf.find(ai - 1)] -= 1
            total += 1
        elif counts[uf.find(bi - 1)] > 0:
            counts[uf.find(bi - 1)] -= 1
            total += 1
    print total

main()
