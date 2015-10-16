#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# pylint: disable=C0111
from sys import stdin, stdout


def main():
    def gcd(a, b):
        while b:
            a, b = b, a % b
        return a
    def can_you(marks, n, m):
        if n < m:
            return 'NO\n'
        msig = sum(marks)
        if msig == 0:
            return 'YES\n'
        for m_i in marks:
            if m_i == 0 or gcd(msig, m_i * n) != msig:
                return 'NO\n'
        return 'YES\n'

    inp = stdin.readlines()
    puts = stdout.write
    for _ in xrange(int(inp[0])):
        puts(can_you(
            map(int, inp[2*_ + 2].split()),
            *map(int, inp[2*_ + 1].split())))

main()

