#!/usr/bin/python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin,star-args
from sys import stdin
from collections import defaultdict

def main():
    def longestPath(curNode, parent):
        ml = 0
        d1, d2 = 0, 0
        for child in tree[curNode]:
            if child != parent:
                lpc, dc = longestPath(child, curNode)
                if lpc > ml:
                    ml = lpc
                if dc >= d1:
                    d1, d2 = dc, d1
                elif dc > d2:
                    d2 = dc
        lp[curNode] = max(ml, d1 + d2 + 1)
        return lp[curNode], d1 + 1

    dstream = iter(stdin.read().split())
    tree = defaultdict(list)
    n = int(next(dstream))
    for x in xrange(n - 1):
        u, v = int(next(dstream)) - 1, int(next(dstream)) - 1
        tree[u].append(v)
        tree[v].append(u)
    lp = [0]*n
    r, q = int(next(dstream)) - 1, int(next(dstream))
    longestPath(r, None)
    for x in xrange(q):
        print lp[int(next(dstream)) - 1] - 1

main()
