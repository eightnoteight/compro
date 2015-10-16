#!/usr/bin/python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
from sys import stdin
from itertools import imap

def main():
    dstream = imap(int, stdin.read().split())
    n, m = next(dstream), next(dstream)
    x, y = next(dstream) - 1, next(dstream) - 1
    mat = [[next(dstream) for _ in xrange(m)] for _ in xrange(n)]
    o = mat[x][y]
    for j in xrange(m - 2, y - 1, -1):
        mat[-1][j] += mat[-1][j + 1]
    for i in xrange(n - 2, x - 1, -1):
        mat[i][-1] += mat[i + 1][-1]
        for j in xrange(m - 2, y - 1, -1):
            mat[i][j] += min(mat[i + 1][j], mat[i][j + 1])
    res = 2*o - mat[x][y]
    if res < 0:
        print 'N'
    else:
        print 'Y', res


main()

