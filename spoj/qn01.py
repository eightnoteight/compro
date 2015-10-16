#!/usr/bin/env python
# -*- encoding: utf-8 -*-

def main():
    n = int(raw_input())
    a = map(int, raw_input().split())
    for x in xrange(1, n):
        a[x] ^= a[x - 1]
    a.append(0)
    m = 0
    for x in xrange(-1, n + 1):
        for y in xrange(x + 1, n + 1):
            if a[x] ^ a[y] > m:
                m = a[x] ^ a[y]
                lo = x + 2
                hi = y + 1
    print m
    print lo, hi

main()
