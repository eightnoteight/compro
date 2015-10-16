#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# pylint: disable=C0111
from sys import stdin


def main():
    def gcd(a, b):
        while b:
            a, b = b, a % b
        return a
    def can_you(marks, n, m):
        msig = sum(marks)
        if n < m:
            return 'NO'
        if msig == 0:
            return 'YES'
        if 0 in marks:
            return 'NO'
        return 'NO' if any(
            [gcd(msig, m_i * n) != msig for m_i in marks]) else 'YES'

    inp = stdin.readlines()
    for _ in xrange(int(inp[0])):
        print can_you(
            map(int, inp[2*_ + 2].split()),
            *map(int, inp[2*_ + 1].split()))

main()
