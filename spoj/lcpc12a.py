#!/usr/bin/python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
from sys import stdin

def main():
    def lcpc(s):
        return sum([i + 1 for i, x in enumerate(map(int, s)) if x % 2 == 0])

    dstream = stdin.read().split()
    for t in xrange(1, int(dstream[0]) + 1):
        res = lcpc(dstream[t])
        print '%s. %s %s' % (t, res, (len(dstream[t])*(len(dstream[t]) + 1)) // 2 - res)

main()
