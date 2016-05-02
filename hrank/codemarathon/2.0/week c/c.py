from sys import stdin

class unionfind(object):
    def __init__(self, n):
        self._number_of_nodes, self._count = n, n
        self.roots, self.weights = list(xrange(n)), [1]*n

    def union(self, a, b):
        self[a] = b

    def find(self, key):
        return self[key]

    def is_connected(self, a, b):
        return self[a, b]

    def __len__(self):
        return self._count

    def __setitem__(self, a, b):
        aroot, broot = self[a], self[b]
        if aroot == broot:
            return
        if self.weights[aroot] > self.weights[broot]:
            aroot, broot = broot, aroot
        self.roots[aroot] = broot
        self.weights[broot] += self.weights[aroot]
        self.weights[aroot] = 0
        self._count -= 1

    def __getitem__(self, key):
        if isinstance(key, tuple):
            tmp = self[key[0]]
            for x in xrange(1, len(key)):
                if self[key[x]] != tmp:
                    return False
            return True
        if isinstance(key, slice):
            return [self[x] for x in xrange(*key.indices(self._number_of_nodes))]
        roots = self.roots
        while roots[key] != key:
            roots[key] = roots[roots[key]]
            key = roots[key]
        return key

def main():
    nextint = iter(map(int, stdin.read().split())).next
    n, q = nextint(), nextint()
    out = []
    uf = unionfind(n)
    for _ in xrange(q):
        if nextint() == 1:
            x, y = nextint() - 1, nextint() - 1
            uf[x] = y
        else:
            x = nextint() - 1
            n = uf.weights[uf.find(x)]
            out.append((n * (n - 1)) // 2)
    print '\n'.join(map(str, out))

main()
