#!/usr/bin/env python
# -*- encoding: utf-8 -*-
from sys import stdin

def main():
    inp = map(int, stdin.read().split())
    for _ in xrange(inp[0]):
        x1, y1, x2, y2 = inp[4*_ + 1], inp[4*_ + 2], inp[4*_ + 3], inp[4*_ + 4]
        print "%.6f" % (((x1 + x2) / 2.0 - x1)**2 + ((y1 + y2) / 2.0 - y1)**2)**0.5

main()
