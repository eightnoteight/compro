#!/usr/bin/env python
# -*- encoding: utf-8 -*-


def main():
    from sys import stdin
    from sys import setrecursionlimit
    setrecursionlimit(2010)
    stdin.readline()
    v = map(int, stdin.read().split())
    memz = {}

    def maxval(l, h, a):
        if l == h:
            return 0
        try:
            return memz[(l, h)]
        except KeyError:
            memz[(l, h)] = max(maxval(l + 1, h, a + 1) + v[l]*a, maxval(l, h - 1, a + 1) + v[h - 1]*a)
            return memz[(l, h)]

    print maxval(0, len(v), 1)

if __name__ == '__main__':
    main()
