#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# pylint: disable=C0111
'''input
2
1
12'''
from sys import stdin


def main():
    favdices = [0]
    for x in xrange(1, 1001):
        n = 0.0
        for y in xrange(1, x + 1):
            n += float(x) / y
        favdices.append(n)
    inp = map(int, stdin.readlines())
    for _ in xrange(inp[0]):
        print '{:.2f}'.format(favdices[inp[_ + 1]])


main()
