#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# pylint: disable=C0111
from sys import stdin
from math import ceil, sqrt


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

    primes = sieve(1000001)
    def is_two_sq(n):
        if n % 4 == 3:
            return 'No'
        for p in primes:
            if p > n:
                break
            if n % p == 0:
                if p % 4 == 3:
                    c = False
                    while n % p == 0:
                        n //= p
                        c = not c
                    if c:
                        return 'No'
                else:
                    while n % p == 0:
                        n //= p
        if n != 1 and n % 4 == 3:
            return 'No'
        return 'Yes'
    inp = map(int, stdin.read().split())
    for x in xrange(inp[0]):
        print is_two_sq(inp[x + 1])

main()

