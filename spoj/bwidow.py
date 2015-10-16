#!/usr/bin/python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
from sys import stdin
from itertools import imap

def main():
    dstream = imap(int, stdin.read().split())
    for _ in xrange(next(dstream)):
        amax = bmax1 = bmax2 = (float('-inf'), -1)
        for i, a, b in zip(xrange(next(dstream)), dstream, dstream):
            if a > amax[0]:
                amax = (a, i)
            if b >= bmax1[0]:
                bmax2, bmax1 = bmax1, (b, i)
            elif b > bmax2[0]:
                bmax2 = (b, i)
        if amax[0] > bmax1[0]:
            print amax[1] + 1
        elif amax[1] == bmax1[1] and amax[0] > bmax2[0]:
            print amax[1] + 1
        else:
            print -1

main()
