#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# pylint: disable=C0111


def main():
    from math import log
    from sys import stdin
    try:
        range = xrange
    except NameError:
        pass
    def factlen(n):
        try:
            return int((log(6.283185307179586*n)/2.0 + n*(log(n) - 1)) \
                       / 2.302585092994046) + 1
        except ValueError:
            return 1


    inp = map(int, stdin.read().split())
    for _ in range(inp[0]):
        x = inp[_ + 1]
        lo = 0
        hi = 1000000001
        while lo < hi:
            n = (lo + hi) // 2
            l = factlen(n)
            if l == x or n == lo or hi == n:
                break
            elif l < x:
                lo = n
            else:
                hi = n
        while l > x:
            n -= 1
            l = factlen(n)
        while l <= x:
            n += 1
            l = factlen(n)
        print n - 1

if __name__ == '__main__':
    main()
