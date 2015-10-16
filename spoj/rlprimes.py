#!/usr/bin/env python
# -*- encoding: utf-8 -*-


def gcd(a, b):
    while b:
        a, b = b, a % b
    return a


def main():
    for _ in xrange(int(raw_input())):
        n = int(raw_input())
        arr = map(int, raw_input().split())
        count = 0
        for x in xrange(n):
            for y in xrange(x + 1, n):
                if gcd(arr[x], arr[y]) == 1:
                    count += 1
        print count

main()
