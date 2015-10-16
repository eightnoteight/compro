#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
import sys


class BIT(object):
    def __init__(self, size):
        self.size = size
        self.tree = [0]*size

    def query(self, idx):
        res = 0
        tree = self.tree
        while idx > 0:
            res += tree[idx]
            idx -= idx & -idx
        return res

    def update(self, idx, val):
        n = self.size
        tree = self.tree
        while idx < n:
            tree[idx] += val
            idx += idx & -idx

def main():
    dstream = iter(map(int, sys.stdin.read().split()))
    out = bytearray()
    for _ in range(next(dstream)):
        res = 0
        n = next(dstream)
        bit = BIT(1000001)
        for _ in range(n):
            tmp = next(dstream)
            if tmp == 0:
                continue
            res += bit.query(tmp - 1)
            bit.update(tmp, tmp)
        out += b'%s\n' % res
    sys.stdout.write(out)


main()
