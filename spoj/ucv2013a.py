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

    dstream = map(int, stdin.read().split())
    dstream.pop()
    dstream.pop()
    dstream = iter(dstream)
    out = []
    m = 1000000007
    for n, l in zip(dstream, dstream):
        out.append(str((n*(pow(n, l, m) - 1)*modinv(n - 1, m)) % m))
    print '\n'.join(out)


main()
