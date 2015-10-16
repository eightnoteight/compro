#!/usr/bin/env python
# -*- encoding: utf-8 -*-

from __future__ import print_function
from sys import stdin

try:
    range = xrange
    input = raw_input
except:
    pass

inp = stdin.readlines()
k = 6.5467418158303285
for _ in range(int(inp[0])):
    print(k*float(inp[_ + 1])**(2/3.0))

