#!/usr/bin/env python
# -*- encoding: utf-8 -*-

from __future__ import print_function
from sys import stdin
try:
    range = xrange
    input = raw_input
except:
    pass

def wtk(n):
    ans = 1
    for x in range(2, n + 1):
        ans = ((ans + (n + 1 - x) - 1) % x) + 1
    return ans

inp = stdin.readlines()
for _ in range(int(inp[0])):
    print(wtk(int(inp[_ + 1])))
