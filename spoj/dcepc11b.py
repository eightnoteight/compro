#!/usr/bin/env python
# -*- encoding: utf-8 -*-
from sys import stdin


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

    inp = stdin.readlines()
    out = []
    for _ in xrange(int(inp[0])):
        n, p = map(int, inp[_ + 1].split())
        if n >= p:
            out.append('0')
            continue
        product = 1
        for x in xrange(p - 1, n, -1):
            product = (product * x) % p
        out.append(str(modinv(-1 * product, p)))

    print '\n'.join(out)
main()

