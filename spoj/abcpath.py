#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,bad-builtin,missing-docstring
from sys import stdin


def main():
    def maxpath(matrix, i, j):
        if i < 0 or i >= n or j < 0 or j >= m:
            return 0
        if memz[i][j]:
            return memz[i][j]
        # neighbour = (neigh_x, neigh_y)
        for neigh_x, neigh_y in zip(
                (i, i, i - 1, i + 1, i - 1, i - 1, i + 1, i + 1),
                (j - 1, j + 1, j, j, j - 1, j + 1, j - 1, j + 1)):
            if matrix[i][j] == matrix[neigh_x][neigh_y] - 1:
                memz[i][j] = max(memz[i][j], maxpath(matrix, neigh_x, neigh_y) + 1)

        return memz[i][j]

    inp = iter(stdin.readlines())
    n, m = map(int, inp.next().split())
    k = 1
    while n or m:
        mat = []
        memz = [[0]*52 for _ in xrange(52)]
        for x in xrange(n):
            mat.append(map(ord, list(inp.next())))
            mat[x].append(0)
            mat[x].append(0)
        mat.append([0] * (m + 2))
        ans = 0
        for x in xrange(n):
            for y in xrange(m):
                if mat[x][y] == 65:
                    ans = max(ans, maxpath(mat, x, y) + 1)
        print 'Case {}: {}'.format(k, ans)
        k += 1
        n, m = map(int, inp.next().split())


main()
