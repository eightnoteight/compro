#!/usr/bin/python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin,star-args
from itertools import groupby
from sys import stdin

def main():
    def all_lcs(a, b):
        def genlcs(r, c):
            if r == 0 or c == 0:
                lcss.append(''.join(reversed(lcs)))
                return
            if dp[r - 1][c - 1] == dp[r][c]:
                genlcs(r - 1, c - 1)
            if dp[r - 1][c - 1] + 1 == dp[r][c] and b[r - 1] == a[c - 1]:
                lcs.append(b[r - 1])
                genlcs(r - 1, c - 1)
                lcs.pop()
            if dp[r - 1][c] == dp[r][c]:
                genlcs(r - 1, c)
            if dp[r][c - 1] == dp[r][c]:
                genlcs(r, c - 1)

        dp = [[0]*(len(a) + 1) for _ in xrange(len(b) + 1)]
        for x in xrange(1, len(b) + 1):
            for y in xrange(1, len(a) + 1):
                dp[x][y] = max(
                    dp[x - 1][y - 1] + (b[x - 1] == a[y - 1]),
                    dp[x - 1][y],
                    dp[x][y - 1]
                )
        lcss = []
        lcs = []
        genlcs(len(b), len(a))
        return lcss
    dstream = iter(stdin.read().split())
    for _ in xrange(int(next(dstream))):
        for x, _ in groupby(sorted(all_lcs(next(dstream), next(dstream)))):
            print x
        print

main()
