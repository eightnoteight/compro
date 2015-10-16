#!/usr/bin/python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin,star-args
from sys import stdin
from itertools import imap

def main():
    dstream = imap(int, stdin.read().split())
    mod = 1000000007
    for case in xrange(1, next(dstream) + 1):
        m, l = next(dstream), next(dstream)
        print "Case %s: %s" % (case,
            ((((pow(m, l + 1, mod) - 1) % mod)*(pow(m - 1, mod - 2, mod))) % mod) if m != 1 else l + 1)

main()
