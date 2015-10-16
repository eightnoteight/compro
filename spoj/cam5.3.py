#!/usr/bin/env python3
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
from sys import stdin
from array import array
#stdin = open('/tmp/spojtest.in', 'r')

class unionfind:
    def __init__(self, n):
        self._length = n
        self._roots = array('L', range(n))
        self._weights = array('L', [1]*n)

    def union(self, a, b):
        aroot = self.find(a)
        broot = self.find(b)
        if aroot == broot:
            return
        elif self._weights[aroot] > self._weights[broot]:
            self._roots[broot] = aroot
            self._weights[aroot] += self._weights[broot]
            self._weights[broot] = 0
        else:
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

    def get_roots(self):
        return self._roots

    def get_weights(self):
        return self._weights

def main():
    istream = map(int, stdin.read().split())
    for _ in range(next(istream)):
        uf = unionfind(next(istream))
        for _ in range(next(istream)):
            uf.union(next(istream), next(istream))
            # print((uf.get_roots(), uf.get_weights()))
        # print((len(set(uf.get_roots())), len(list(filter(None, uf.get_weights())))))
        print(len(list(filter(None, uf.get_weights()))))


main()
