#!/usr/bin/env python
# -*- encoding: utf-8 -*-

def main():
    def minpath1(grid, n):
        for x in xrange(n - 2, -1, -1):
            grid[x][0] += min(grid[x + 1][0], grid[x + 1][1])
            for y in xrange(1, m -1):
                grid[x][y] += min(grid[x + 1][y - 1], grid[x + 1][y], grid[x + 1][y + 1])
            grid[x][-1] += min(grid[x + 1][-1], grid[x + 1][-2])
        print min(grid[0])

    def minpath2(grid, n):
        a = 0
        for x in xrange(n):
            a += grid[x][0]
        print a

    n, m = map(int, raw_input().split())
    grid = []
    for x in xrange(n):
        grid.append(map(int, raw_input().split()))
    if m == 1:
        minpath2(grid, n)
    else:
        minpath1(grid, n)


main()
