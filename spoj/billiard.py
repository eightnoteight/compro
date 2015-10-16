#!/usr/bin/python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
from sys import stdin
from math import atan2, degrees, sqrt
from itertools import imap, izip

def main():
    dstream = imap(float, stdin.read().split())
    try:
        for a, b, s, m, n in izip(dstream, dstream, dstream, dstream, dstream):
            print "%.2f %.2f" % (degrees(atan2(n*b, m*a)), sqrt((m*a / s)**2 + (n*b / s)**2))
    except ZeroDivisionError:
        pass

main()
