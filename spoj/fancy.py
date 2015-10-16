#!/usr/bin/env python
# encoding: utf-8
# pylint: disable=C0111
from sys import stdin


def main():
    out = []
    gch = stdin.read
    for _ in xrange(int(stdin.readline())):
        prod = 0
        c = ''
        while not c.isdigit():
            c = gch(1)
            if c is '':
                break
        s = 0
        while c.isdigit():
            n = gch(1)
            if n == c:
                s += 1
            else:
                prod += s
                s = 0
                c = n
            if n is '':
                break
        out.append(str(1 << prod))
    print '\n'.join(out)

try:
    main()
except EOFError:
    pass
