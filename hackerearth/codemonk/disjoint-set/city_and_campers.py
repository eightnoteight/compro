from sys import stdin
from heapq import heappop, heappush, heapify
from collections import defaultdict

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


class CustomHeap(object):
    def __init__(self, arr):
        self.minheap = [[x, False] for x in arr]
        self.maxheap = [[-x, False] for x in arr]
        heapify(self.minheap)
        heapify(self.maxheap)
        self.minrefs = defaultdict(list)
        self.maxrefs = defaultdict(list)
        for x in self.minheap:
            self.minrefs[x[0]].append(x)
        for x in self.maxheap:
            self.maxrefs[x[0]].append(x)

    def insert(self, x):
        mir, mar = [x, False], [-x, False]
        heappush(self.minheap, mir)
        heappush(self.maxheap, mar)
        self.minrefs[mir[0]].append(mir)
        self.maxrefs[mar[0]].append(mar)

    def delete(self, x):
        ref = self.minrefs[x].pop()
        ref[1] = True
        ref = self.maxrefs[-x].pop()
        ref[1] = True

    def max(self):
        while self.maxheap[0][1]:
            heappop(self.maxheap)
        return -self.maxheap[0][0]

    def min(self):
        while self.minheap[0][1]:
            heappop(self.minheap)
        return self.minheap[0][0]

def main():
    nextint = iter(map(int, stdin.read().split())).next
    n, q = nextint(), nextint()
    uf = unionfind(n)
    myds = CustomHeap(uf.weights)
    for _ in xrange(q):
        a, b = nextint() - 1, nextint() - 1
        if uf[a] != uf[b]:
            myds.delete(uf.weights[uf[a]])
            myds.delete(uf.weights[uf[b]])
            uf[a] = b
            myds.insert(uf.weights[uf.find(a)])
        print myds.max() - myds.min()

main()
