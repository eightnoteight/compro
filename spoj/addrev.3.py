#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
from sys import stdin
'''input
'''


def main():
    inp = stdin.readlines()
    out = []
    for _ in range(int(inp[0])):
        a, b = inp[_ + 1].split()
        out.append(str(int(a[::-1]) + int(b[::-1]))[::-1].lstrip('0'))
    print('\n'.join(out))


main()
