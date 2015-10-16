#!/usr/bin/python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
from sys import stdin

def main():
    dstream = iter(stdin.read().split())
    for t in xrange(1, int(next(dstream)) + 1):
        a, b = int(next(dstream), 2), int(next(dstream), 2)
        print 'Case %s: %s' % (
            t, 'YES' if b != 0 and a % b == 0 else 'NO')

main()
