#!/usr/bin/env python3
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
from sys import stdin


def main():
    inp = stdin.read().split()
    out = []
    puts = out.append
    for _ in range(int(inp[0])):
        s = inp[_ + 1] + inp[_ + 1]
        n = len(s) // 2
        m = 0
        for x in range(n):
            if s[m: m + n] > s[x: x + n]:
                m = x
        puts(str(m + 1))
    print('\n'.join(out))


main()
