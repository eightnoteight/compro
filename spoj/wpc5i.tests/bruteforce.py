#!/usr/bin/python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
from fractions import gcd

def main():
    def lcm(a, b):
        return (a*b) / gcd(a, b)
    for t in xrange(int(raw_input())):
        n, m = map(int, raw_input().split())
        for x in xrange(1, max(n*n, m*m)):
            if lcm(n, x) % m == 0 == lcm(m, x) % n:
                print x
                break

main()
