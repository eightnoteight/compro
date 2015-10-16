#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
from sys import stdin

def warshall(adjMat, n):
    dp = adjMat
    for k in xrange(n):
        for i in xrange(n):
            for j in xrange(n):
                if dp[i][k] + dp[k][j] < dp[i][j]:
                    dp[i][j] = dp[i][k] + dp[k][j]
    return dp

def main():
    dstream = stdin.readlines()
    n, e, t, m = (int(dstream[x]) for x in xrange(4))
    maze = [[float('inf')]*n for _ in xrange(n)]
    for x in xrange(m):
        a, b, w = map(int, dstream[x + 4].split())
        maze[a - 1][b - 1] = w
    paths = warshall(maze, n)
    paths[e - 1][e - 1] = 0
    count = 0
    for x in xrange(n):
        if paths[x][e - 1] <= t:
            count += 1
    print count

main()
