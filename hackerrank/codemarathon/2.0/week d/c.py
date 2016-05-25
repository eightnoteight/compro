from sys import stdin
from heapq import heapify, heappop, heappush
from collections import defaultdict

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a


class unionfind(object):
    def __init__(self, n, strengths):
        self._number_of_nodes, self._count = n, n
        self.roots, self.weights = list(xrange(n)), [1]*n
        self.strengths = strengths
        self.maxstrength = [-x for x in strengths]
        heapify(self.maxstrength)
        self.ss = defaultdict(int)
        for x in strengths:
            self.ss[x] += 1

    def union(self, a, b):
        if self[a] == self[b]:
            return
        aroot = self[a]
        broot = self[b]
        self.ss[self.strengths[aroot]] -= 1
        self.ss[self.strengths[broot]] -= 1
        gab = gcd(self.strengths[aroot], self.strengths[broot])
        self[a] = b
        self.strengths[self[a]] = gab
        self.ss[gab] += 1
        heappush(self.maxstrength, -gab)

    def getmstrength(self):
        while self.ss[-self.maxstrength[0]] <= 0:
            heappop(self.maxstrength)
        return -self.maxstrength[0]

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
    # next = iter(stdin.read().split()).next
    nextint = iter(map(int, stdin.read().split())).next
    n, m, q = nextint(), nextint(), nextint()
    strengths = [nextint() for _ in xrange(n)]
    edges = [(nextint() - 1, nextint() - 1) for _ in xrange(m)]
    qs = [nextint() - 1 for _ in xrange(q)][::-1]
    answers = []
    uf = unionfind(n, strengths)
    for qx in set(xrange(m)) - set(qs):
        x, y = edges[qx]
        uf.union(x, y)

    for qx in xrange(q):
        x, y = edges[qs[qx]]
        answers.append(uf.getmstrength())
        uf.union(x, y)
    print '\n'.join(map(str, answers[::-1]))



main()

