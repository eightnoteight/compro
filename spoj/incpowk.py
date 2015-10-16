#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# pylint: disable=C0111
from sys import stdin
from bisect import bisect_left as bisect

# GleanStart
# 8
# 3 4
# 3 100
# 4 3
# 5 12
# 6 7
# 7 239
# 8 17
# 9 500
# GleanEnd

def main():
    pow2m1 = [2]
    for _ in xrange(666):
        pow2m1.append(pow2m1[-1]*2)

    for x in xrange(len(pow2m1)):
        pow2m1[x] -= 1

    inp = map(int, stdin.read().split())
    for _ in xrange(inp[0]):
        k, n = inp[2*_ + 1], inp[2*_ + 2]
        s = 0
        while n > 0:
            # print n
            t = bisect(pow2m1, n)
            n -= pow2m1[t - 1] + 1
            s += pow(k, t)
        print s

main()
