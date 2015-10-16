#!/usr/bin/env python
# -*- encoding: utf-8 -*-

try:
    range = xrange
    input = raw_input
except:
    pass


n, d = map(int, input().split())

while n and d:
    ans = 1  # for josephous(1, k)
    for x in range(2, n + 1):
        ans = ((ans + d - 1) % x) + 1
    print n, d, ans
    n, d = map(int, input().split())
