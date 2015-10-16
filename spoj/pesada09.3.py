#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
from sys import stdin

stdin = open('/tmp/spojtest.in', 'r')



def main():
    def isavl(bst):
        depth = [0]*(2*len(bst) + 10)
        for x in range(len(bst)):
            if bst[x] != -1:
                depth[x] = 1
                x = (x - 1) // 2
                while x >= 0:
                    depth[x] = max(depth[2*x + 1], depth[2*x + 2]) + 1
                    x = (x - 1) // 2
        for x in range(len(bst)):
            if abs(depth[2*x + 1] - depth[2*x + 2]) > 1:
                return False
        return True

    idata = map(int, stdin.read().split())
    out = []
    for _ in range(next(idata)):
        bst = [next(idata) for _ in range(next(idata))]
        out.append('T' if isavl(bst) else 'F')
    print('\n'.join(out))


main()
