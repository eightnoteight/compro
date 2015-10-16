#!/usr/bin/python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
from math import ceil, sqrt
from heapq import heappush, heappop

def main():
    def gcd(a, b):
        while b:
            a, b = b, a % b
        return a
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
        arr[1] = 1
        for x in xrange(int(ceil(sqrt(n))) + 1, 1, -1):
            if arr[x]:
                y = x
                while y < n:
                    arr[y] = y
                    y *= x
        return filter(None, arr)

    n, k = map(int, raw_input().split())
    numbers = sieve(100001)
    coprime4, m = [], float('-inf')
    for _ in xrange(n):
        x1 = heappop(numbers)
        tmp = []
        while True:
            x2 = heappop(numbers)
            if gcd(x2, x1) == 1:
                for t in tmp:
                    heappush(numbers, t)
                break
            tmp.append(x2)
        tmp = []
        while True:
            x3 = heappop(numbers)
            if gcd(x3, x1) == 1 and gcd(x3, x2) == 1:
                for t in tmp:
                    heappush(numbers, t)
                break
            tmp.append(x3)
        tmp = []
        while True:
            x4 = heappop(numbers)
            if gcd(x4, x1) == 1 and gcd(x4, x2) == 1 and gcd(x4, x3) == 1:
                for t in tmp:
                    heappush(numbers, t)
                break
            tmp.append(x4)
        coprime4.append((k*x1, k*x2, k*x3, k*x4))
        m = max(m, max(coprime4[-1]))
    print m
    for p, q, r, s in  coprime4:
        print p, q, r, s



main()
