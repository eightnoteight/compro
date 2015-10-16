#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# pylint: disable=C0111
from math import ceil, sqrt
from sys import stdin
# from itertools import imap, ifilter


def main():
    def sieve(n):
        arr = [x for x in xrange(n)]
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

    primes = sieve(31625)

    def segmented_sieve(primes, i, j):
        j += 1
        if i == 1:
            i = 2
        arr = [x for x in xrange(i, j)]
        for prime in primes:
            if prime >= j:
                break
            start = prime*int(ceil(i / float(prime)))
            if start == prime:
                start = 2 * start
            arr[start - i: j - i: prime] = \
                [0] * len(xrange(start - i, j - i, prime))
        return map(str, filter(None, arr))
    inp = map(int, stdin.read().split())
    for x in xrange(inp[0]):
        print '\n'.join(segmented_sieve(primes, inp[2*x + 1], inp[2*x + 2]))
        print

main()
