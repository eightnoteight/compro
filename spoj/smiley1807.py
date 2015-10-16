#!/usr/bin/python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
from sys import stdin

def main():
    arr = map(int, stdin.read().strip())
    oezs = [float('-inf') for _ in xrange(5)]
    oezs[-1] = 0
    oezsf = [1, 8, 0, 7].index
    for x in reversed(arr):
        oezs[oezsf(x)] = max(oezs[oezsf(x)] + 1, oezs[oezsf(x) + 1] + 1)
    print max(oezs[0], 0)

main()
