#!/usr/bin/env python
# -*- encoding: utf-8 -*-

try:
    range = xrange
    input = raw_input
except:
    pass

from sys import stdin, stdout

inp = map(int, stdin.read().split())
for _ in range(inp[0]):
    stdout.write('%d\n' % (((inp[_ + 1]*(3*inp[_ + 1] + 1)) // 2) % 1000007))
