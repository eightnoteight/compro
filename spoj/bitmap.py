#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# pylint: disable=C0111
'''input
2
3 4
0001
0011
0110

3 4
0001
0011
0110
'''
from collections import deque
from sys import stdin


def conquer(mat, ans, ii, jj, n, m):
    mark = [True]*(n*m)
    queue = deque([None, (ii, jj)])
    ans[ii][jj] = 0
    dist = 0
    while len(queue) > 1:
        node = queue.popleft()
        if node is None:
            queue.append(None)
            dist += 1
            continue
        x, y = node
        mark[x*m + y] = False
        if x > 0 and mark[(x - 1)*m + y] and ans[x - 1][y] > dist:
            queue.append((x - 1, y))
            ans[x - 1][y] = dist
            mark[(x - 1)*m + y] = False
        if x < n - 1 and mark[(x + 1)*m + y] and ans[x + 1][y] > dist:
            queue.append((x + 1, y))
            ans[x + 1][y] = dist
            mark[(x + 1)*m + y] = False
        if y > 0 and mark[x*m + y - 1] and ans[x][y - 1] > dist:
            queue.append((x, y - 1))
            ans[x][y - 1] = dist
            mark[x*m + y - 1] = False
        if y < m - 1 and mark[x*m + y + 1] and ans[x][y + 1] > dist:
            queue.append((x, y + 1))
            ans[x][y + 1] = dist
            mark[x*m + y + 1] = False


def main():
    for _ in xrange(int(raw_input())):
        n, m = map(int, raw_input().split())
        mat = [None]*n
        ans = [[4000]*m for _ in xrange(n)]
        for x in xrange(n):
            mat[x] = raw_input()
        for x in xrange(n):
            for y in xrange(m):
                if mat[x][y] == '1':
                    conquer(mat, ans, x, y, n, m)
        for x in xrange(n):
            for y in xrange(m):
                print ans[x][y],
            print
        raw_input()

main()
