#!/usr/bin/python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
from sys import stdin
from itertools import imap

def main():
    def extended_gcd(aa, bb):
        lastremainder, remainder = abs(aa), abs(bb)
        x, lastx, y, lasty = 0, 1, 1, 0
        while remainder:
            lastremainder, (quotient, remainder) = \
                remainder, divmod(lastremainder, remainder)
            x, lastx = lastx - quotient * x, x
            y, lasty = lasty - quotient * y, y
        return lastremainder, lastx * (-1 if aa < 0 else 1), \
            lasty * (-1 if bb < 0 else 1)

    def modinv(a, m):
        g, x, _ = extended_gcd(a, m)
        if g != 1:
            raise ValueError
        return x % m

    dstream = imap(int, stdin.read().split())
    for _ in xrange(next(dstream)):
        n = next(dstream)
        print ((pow(10, n, 314159) + pow(8, n, 314159))*modinv(2, 314159)) % 314159

main()
