#!/usr/bin/python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
from sys import stdin

def main():
    dstream = iter(stdin.read().split())
    for _ in xrange(int(next(dstream))):
        alok, nath = map(ord, next(dstream)), map(ord, next(dstream))
        k = int(next(dstream))
        n, m = len(alok), len(nath)
        dp = [[0]*(m + 1) for _ in xrange(n + 1)]
        kdp = [[0]*m for _ in xrange(n)]
        for x in xrange(1, n + 1):
            kdp[x - 1] = kdp[x - 2][:]
            for y in xrange(1, m + 1):
                if alok[x - 1] == nath[y - 1]:
                    dp[x][y] = dp[x - 1][y - 1] + (alok[x - 1] == nath[y - 1])
                    kdp[x - 1][0] = max(kdp[x - 1][0], alok[x - 1])
                    for z in xrange(1, dp[x][y]):
                        kdp[x - 1][z] = max(
                            kdp[x - 1][z],
                            kdp[x - 2][z - 1] + alok[x - 1])
                else:
                    dp[x][y] = max(dp[x][y - 1], dp[x - 1][y], dp[x - 1][y - 1])
        for x in kdp:
            print x
        if k - 1 < m:
            print kdp[-1][k - 1]
        else:
            print 0

main()
