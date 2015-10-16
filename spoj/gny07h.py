#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# pylint: disable=C0111
'''input
4
2
3
7
999
'''
from sys import setrecursionlimit
setrecursionlimit(2011)


def main():
    cache = {}

    def grid_tile(a, b, c, d):
        if a < 0 or b < 0 or c < 0 or d < 0:
            return 0
        if a == b == c == d == 0 or a == b == c == d == 1:
            return 1
        w = 0
        if a == b == c == d:
            paths = [
                (a - 1, b - 1, c - 1, d - 1),
                (a - 2, b - 2, c - 1, d - 1),
                (a - 1, b - 1, c - 2, d - 2),
                (a - 2, b - 1, c - 1, d - 2),
                (a - 2, b - 2, c - 2, d - 2)
            ]
        elif a == b == c + 1 == d + 1:
            paths = [
                (a - 1, b - 1, c, d),
                (a - 2, b - 2, c, d)
            ]
        elif a + 1 == b == c == d + 1:
            paths = [
                (a, b - 1, c - 1, d),
                (a, b - 2, c - 2, d)
            ]
        elif a == b + 1 == c + 1 == d:
            paths = [
                (a - 2, b, c, d - 2)
            ]
        elif a + 1 == b + 1 == c == d:
            paths = [
                (a, b, c - 1, d - 1),
                (a, b, c - 2, d - 2)
            ]
        else:
            paths = []
        for elem in paths:
            try:
                w += cache[elem]
            except KeyError:
                c = cache[elem] = grid_tile(*elem)
                w += c
        return w

    for x in xrange(int(raw_input())):
        n = int(raw_input())
        print x + 1, grid_tile(n, n, n, n)


main()
