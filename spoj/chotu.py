#!/usr/bin/python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
from sys import stdin
from math import sqrt
from itertools import imap, izip

def main():
    dstream = imap(int, stdin.read().split())
    next(dstream)
    for x, y in izip(dstream, dstream):
        print "%.3f" % (2*sqrt(abs(x*x - y*y)))

main()
