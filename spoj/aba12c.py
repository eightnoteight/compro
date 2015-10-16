#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# pylint: disable=C0111
'''input
3
3 5
-1 -1 4 5 -1
5 5
1 2 3 4 5
3 23
-1 -1 3 -1 -1 -1 7 -1 -1 -1 -1 -1 13 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
'''
from sys import stdin


def buy_g(arr, n, k):
    mat = [[(float('inf'), 0)]*(k + 1) for _ in xrange(len(arr) + 1)]
    for x in xrange(1, len(arr) + 1):
        for y in xrange(1, k + 1):
            if arr[x - 1][1] > y:
                mat[x][y] = mat[x - 1][y]
            elif arr[x - 1][1] == y:
                if mat[x - 1][y] < (arr[x - 1][0], 1):
                    mat[x][y] = mat[x - 1][y]
                else:
                    mat[x][y] = (arr[x - 1][0], 1)
            else:
                a, b = mat[x][y - arr[x - 1][1]]
                if (a + arr[x - 1][0], b) < mat[x - 1][y] and b < n:
                    mat[x][y] = (a + arr[x - 1][0], b + 1)
                else:
                    mat[x][y] = mat[x - 1][y]

    if mat[-1][-1][0] == float('inf'):
        return -1
    else:
        return mat[-1][-1][0]


def main():
    buy = buy_g
    inp = stdin.readlines()

    for t in xrange(int(inp[0])):
        n, k = map(int, inp[2*t + 1].split())
        arr = []
        for x, ap in enumerate(map(int, inp[2*t + 2].split())):
            if ap != -1:
                arr.append((ap, x + 1))
        print buy(arr, n, k)

main()
