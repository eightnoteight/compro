#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
'''input

'''
from sys import stdin


def main():
    inp = iter(map(int, stdin.read().split()))
    for _ in xrange(next(inp)):
        n, k, _, f = next(inp), next(inp), next(inp), next(inp)
        print n + (((f - n)*k) // (k - 1))


main()
