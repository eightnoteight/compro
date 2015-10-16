#!/usr/bin/python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
from sys import stdin
from itertools import imap

def main():
    def gcd(a, b):
        while b:
            a, b = b, a % b
        return a
    dstream = imap(int, stdin.read().split())
    for _ in xrange(next(dstream)):
        x, y, z = next(dstream), next(dstream), next(dstream)
        if z <= max(x, y) and gcd(z, gcd(x, y)) == gcd(x, y):
            print 'YES'
        else:
            print 'NO'

main()
