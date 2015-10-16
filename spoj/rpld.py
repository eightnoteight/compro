#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
from sys import stdin

def main():
    out = bytearray()
    nt = iter(stdin.readlines()).next
    for t in xrange(1, int(nt()) + 1):
        _, r = map(int, nt().split())
        if len(set(nt() for _ in xrange(r))) != r:
            out.extend('Scenario #%s: impossible\n' % t)
        else:
            out.extend('Scenario #%s: possible\n' % t)
    print out

main()
