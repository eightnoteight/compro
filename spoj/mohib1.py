#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
from sys import stdin

def main():
    def answer(n):
        return bytes(((((n*(n + 1)) / 2)**2) - ((n*(n + 1)*(2*n + 1)) / 6)) / 2)
    dstream = map(int, stdin.readlines())
    print '\n'.join(map(str, [answer(dstream[t]) for t in xrange(1, dstream[0] + 1)]))

main()
