#!/usr/bin/python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
from sys import stdin

def main():
    def mw_shed(intervals):
        currentProfit = [0]
        for x, y in sorted(intervals, key=lambda z: z[::-1]):
            for _ in xrange(len(currentProfit), y + 1):
                currentProfit.append(currentProfit[-1])
            currentProfit[y] = max(currentProfit[y], currentProfit[x] + y - x)
        return max(currentProfit)

    dstream = iter(stdin.read().split())
    for _, n, expr in zip(xrange(int(next(dstream))), dstream, dstream):
        n = int(n)
        arr = [0]
        for x in expr:
            arr.append(arr[-1] + (-1 if x == '0' else 1))
        intervals = []
        for x in xrange(n + 1):
            for y in xrange(x + 1, n + 1):
                if arr[y] - arr[x] >= 1:
                    intervals.append((x, y))
        print mw_shed(intervals)

main()
