#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# pylint: disable=C0111
from math import sqrt
from sys import stdin

# GleanStart
#2
#1 100
#12 100
# GleanEnd

def main():
    f = [0, 1]
    for _ in xrange(40):
        f.append(f[-1] + f[-2])

    def is_handsome(fibs, n, m):
        if n <= 3:
            return True
        sumpd = -n - int(sqrt(n)) * sqrt(n).is_integer() + sum(
            [x + n // x for x in xrange(1, int(sqrt(n)) + 1) if n % x == 0])
        sumpd %= m
        return 2*len([
            x for x in xrange(1, int(sqrt(sumpd)) + 1) if sumpd % x == 0
        ]) - sqrt(sumpd).is_integer() - 1 in fibs

    inp = map(int, stdin.read().split())
    out = []

    for t in xrange(inp[0]):
        out.append('Case #{} : {}.'.format(
            t + 1,
            'YES' if is_handsome(f, inp[2*t + 1], inp[2*t + 2]) else 'NO'))
    print '\n'.join(out)

main()

