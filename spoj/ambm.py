#!/usr/bin/env python
# -*- encoding: utf-8 -*-
from sys import stdin


def main():
    inp = stdin.readlines()
    for _ in xrange(int(inp[0])):
        n, k = map(int, inp[2*_ + 1].split())
        a = map(int, inp[2*_ + 2].split())
        for x in xrange(1, k):
            a[x] += 2*a[x - 1]

        for x in xrange(1, k):
            pass

main()
