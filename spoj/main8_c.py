#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
from sys import stdin
from itertools import imap

def main():
    dstream = imap(int, stdin.read().split())
    for _ in xrange(next(dstream)):
        n, k = next(dstream), next(dstream)
        arr = sorted([next(dstream) for _ in xrange(n)])
        out = float('-inf')
        for x in xrange(n):
            if (arr[x]*(n - x)) // k > out:
                out = (arr[x]*(n - x)) // k
        if n >= k and arr[n - k] > out:
            out = arr[n - k]
        print out

main()
