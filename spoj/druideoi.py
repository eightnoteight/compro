#!/usr/bin/python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
from sys import stdin
from itertools import imap

def main():
    dstream = imap(int, stdin.read().split())
    for _ in xrange(next(dstream)):
        n = next(dstream)
        # print "n = ", n
        arr = [next(dstream) for x in xrange(n)]
        lhs = [-1]*n
        rhs = [-1]*n
        memback = []
        for x in xrange(n):
            while memback and arr[x] >= memback[-1][0]:
                memback.pop()
            if memback:
                lhs[x] = memback[-1][1]
            memback.append((arr[x], x + 1))
        for x in xrange(n):
            while memback and arr[x] >= memback[-1][0]:
                memback.pop()
            if memback:
                lhs[x] = memback[-1][1]
            memback.append((arr[x], x + 1))
        memback = []
        arr.reverse()
        for x in xrange(n):
            while memback and arr[x] >= memback[-1][0]:
                memback.pop()
            if memback:
                rhs[x] = n - memback[-1][1] + 1
            memback.append((arr[x], x + 1))
        for x in xrange(n):
            while memback and arr[x] >= memback[-1][0]:
                memback.pop()
            if memback:
                rhs[x] = n - memback[-1][1] + 1
            memback.append((arr[x], x + 1))
        rhs.reverse()
        print '\n'.join(["%s %s" % x for x in zip(lhs, rhs)])

main()
