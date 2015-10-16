#!/usr/bin/python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
from sys import stdin
from itertools import imap, izip

def main():
    def gcd(a, b):
        while b:
            a, b = b, a % b
        return a
    dstream = imap(int, stdin.read().split())
    for _, a, b in izip(xrange(next(dstream)), dstream, dstream):
        print abs((a - b) // gcd(a, b))

main()
