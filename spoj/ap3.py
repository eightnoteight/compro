#!/usr/bin/env python
# -*- encoding: utf-8 -*-

def main():
    from sys import stdin
    inp = map(int, stdin.read().split())
    for _ in xrange(inp[0]):
        p, q, r = inp[3*_ + 1], inp[3*_ + 2], inp[3*_ + 3]
        n = int(((7*p + 5*q + 2*r) + (((7*p + 5*q + 2*r)**2 - 48*((p + q)*r))**0.5)) // (2*(p + q)))
        d = int((q - p) // (n - 6))
        a = int(p - 2*d)
        print(n)
        for x in xrange(n):
            print a,
            a += d
        print
main()
