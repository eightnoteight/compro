#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
from sys import stdin


def main():

    def extended_gcd(aa, bb):
        lastr, remainder = abs(aa), abs(bb)
        x, lastx, y, lasty = 0, 1, 1, 0
        while remainder:
            lastr, (quotient, remainder) = remainder, divmod(lastr, remainder)
            x, lastx = lastx - quotient * x, x
            y, lasty = lasty - quotient * y, y
        return lastr, lastx * (-1 if aa < 0 else 1), lasty * (-1 if bb < 0 else 1)

    def modinv(a, m):
        g, x, _ = extended_gcd(a, m)
        if g != 1:
            raise ValueError
        return x % m

    m = 1000000007
    fact = [x for x in xrange(1, 2000002)]
    for x in xrange(1, 2000001):
        fact[x] *= fact[x - 1]
        fact[x] %= m
    raw_input = stdin.readline
    for _ in xrange(int(raw_input())):
        x, y = map(int, raw_input().split())
        if x == 0 or y == 0:
            print 1
        else:
            print (fact[x + y - 1] * modinv((fact[x - 1] * fact[y - 1]) % m, m)) % m
main()
