#!/usr/bin/env python
# -*- encoding: utf-8 -*-


# fuck why can't i solve this fucking question!!!!!!!!!!
# this is simple
from sys import stdin

def main():
    def solve(c, w, W, n):
        inf = float('inf')
        dp = [[0]*(W + 1) for x in xrange(n + 1)]
        dp[0][1:] = [inf]*W
        for x in xrange(1, n + 1):
            for y in xrange(1, W + 1):
                dp[x][y] = min(
                    dp[x - 1][y],  # no picks.
                    (dp[x - 1][y - w[x - 1]] if w[x - 1] <= y else inf) + c[x - 1],  # one pick.
                    (dp[x][y - w[x - 1]] if w[x - 1] <= y else inf) + c[x - 1]  # one or more picks.
                )
        return dp[-1][-1]



    inp = map(int, stdin.read().split())
    inpi = 1
    for _ in xrange(inp[0]):
        W = inp[inpi + 1] - inp[inpi]
        n = inp[inpi + 2]
        inpi += 3
        p = []
        w = []
        for x in xrange(n):
            p.append(inp[inpi])
            w.append(inp[inpi + 1])
            inpi += 2
        ans = solve(p, w, W, n)
        if ans == float('inf'):
            print 'This is impossible.'
        else:
            print 'The minimum amount of money in the piggy-bank is %d.' % ans

if __name__ == '__main__':
    main()
