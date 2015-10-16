#!/usr/bin/python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
from sys import stdin

def main():
    disp = {
        '063': '0', '010': '1', '093': '2', '079': '3', '106': '4',
        '103': '5', '119': '6', '011': '7', '127': '8', '107': '9'
    }
    back = {
        '0': '063', '1': '010', '2': '093', '3': '079', '4': '106',
        '5': '103', '6': '119', '7': '011', '8': '127', '9': '107'
    }
    dstream = stdin.read().split()
    dstream.pop()
    out = bytearray()
    puts = out.extend
    for expr in dstream:
        p = expr.index('+')
        a, b = expr[: p], expr[p + 1: -1]
        a = int(''.join([disp[a[x: x + 3]] for x in xrange(0, len(a), 3)]))
        b = int(''.join([disp[b[x: x + 3]] for x in xrange(0, len(b), 3)]))
        puts('%s%s\n' % (expr, ''.join([back[x] for x in str(a + b)])))
    print out

main()
