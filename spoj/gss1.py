#!/usr/bin/python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin,star-args
from sys import stdin
from itertools import imap

def main():
    dstream = imap(int, stdin.read().split())
    n = next(dstream)
    arr = [next(dstream) for _ in xrange(n)]
    msums = [0]
    zinds = []
    for x in xrange(arr):
        msums.append(arr[x] + msums[-1])
        if msums[-1] < 0:
            msums[-1] = 0
            zinds.append(x)
    for _ in xrange(next(dstream)):
        x, y = next(dstream), next(dstream)

main()
