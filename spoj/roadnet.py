#!/usr/bin/python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
from sys import stdin
from itertools import imap

def main():
    def getAdjMat(mat, n):
        for k in xrange(n - 1, -1, -1):
            for i in xrange(n - 1, -1, -1):
                for j in xrange(n - 1, -1, -1):
                    if i != j and j != k and i != k and mat[i][k] + mat[k][j] == mat[i][j]:
                        mat[i][j] = float('inf')
        for i in xrange(n):
            mat[i][i] = float('inf')
        for i in xrange(n):
            for j in xrange(n):
                if mat[i][j] == mat[j][i]:
                    mat[max(j, i)][min(i, j)] = float('inf')
        return mat

    dstream = imap(int, stdin.read().split())
    for _ in xrange(next(dstream)):
        n = next(dstream)
        mat = [[next(dstream) for _ in xrange(n)] for _ in xrange(n)]
        adjMat = getAdjMat(mat, n)
        for i in xrange(n):
            for j in xrange(n):
                if adjMat[i][j] != float('inf'):
                    print i + 1, j + 1
        print

main()
