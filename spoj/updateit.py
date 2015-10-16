#!/usr/bin/python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
from sys import stdin
from itertools import imap

def main():
    dstream = imap(int, stdin.read().split())
    for _ in xrange(next(dstream)):
        n, u = next(dstream), next(dstream)
        arr = [0]*(n + 1)
        for _ in xrange(u):
            l, r, v = next(dstream), next(dstream), next(dstream)
            arr[l] += v
            arr[r + 1] -= v
        for x in xrange(1, n + 1):
            arr[x] += arr[x - 1]
        for _ in xrange(next(dstream)):
            print arr[next(dstream)]

main()
