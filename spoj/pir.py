#!/usr/bin/env python
# -*- encoding: utf-8 -*-

from __future__ import print_function
from sys import stdin
from math import sqrt

try:
    range = xrange
    input = raw_input
except:
    pass


inp = stdin.readlines()
for _ in range(int(inp[0])):
    u, v, w, W, V, U = map(int, inp[_ + 1].split())
    u1 = v*v + w*w - U*U
    v1 = w*w + u*u - V*V
    w1 = u*u + v*v - W*W
    vol = sqrt(4*u*u*v*v*w*w - u*u*u1*u1 - v*v*v1*v1 - w*w*w1*w1+u1*v1*w1) / 12.0
    print('{:.4f}'.format(vol))
