#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
import sys


def main():
    dstream = map(int, sys.stdin.read().split())
    out = bytearray()
    for _ in range(next(dstream)):
        x = next(dstream)
        out.extend(map(ord, '{} {}\n'.format((x + 1) - 2**bin(x).count('1'), 2**bin(x).count('1'))))
    print (str(out, encoding='ascii'))


main()
