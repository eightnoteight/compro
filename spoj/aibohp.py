#!/usr/bin/python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin

def main():
    inf = float('inf')
    for _ in xrange(int(raw_input())):
        s = raw_input()
        n = len(s)
        dp = [[0]*x for x in xrange(n + 1, 0, -1)]
        for y in xrange(2, n + 1):
            for x in xrange(n - y + 1):
                dp[y][x] = min(
                    dp[y - 1][x + 1] + 1,
                    dp[y - 1][x] + 1,
                    dp[y - 2][x + 1] if s[x] == s[x + y - 1] else inf)
        print dp[-1][-1]

main()
