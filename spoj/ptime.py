#!/usr/bin/python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
from math import ceil, sqrt
from collections import defaultdict

def main():
    def sieve(n):
        arr = range(n)
        for x in xrange(4, n, 2):
            arr[x] = 0
        for x in xrange(9, n, 6):
            arr[x] = 0
        arr[1] = 0
        for x in xrange(1, int(ceil((sqrt(n) + 1) / 6.0)) + 1):
            if arr[6*x - 1]:
                arr[(6 * x - 1) * (6 * x - 1): n: 2 * (6 * x - 1)] = \
                    [0]*int(ceil((n - (6 * x - 1)*(6 * x - 1)) \
                                 / float(2 * (6 * x - 1))))
            if arr[6*x + 1]:
                arr[(6 * x + 1) * (6 * x + 1): n: 2 * (6 * x + 1)] = \
                    [0]*int(ceil((n - (6 * x + 1)*(6 * x + 1)) \
                                 / float(2 * (6 * x + 1))))
        return filter(None, arr)


    n = int(raw_input())
    primes = sieve(n + 1)
    out = defaultdict(int)
    for p in primes:
        f = p
        while f <= n:
            out[p] += n // f
            f *= p
    print ' * '.join(map('{0[0]}^{0[1]}'.format, sorted(out.items())))


main()

