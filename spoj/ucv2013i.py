#!/usr/bin/python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
from sys import stdin
from itertools import imap
from math import sin, pi

def main():
    dstream = imap(int, stdin.read().split())
    try:
        while True:
            r, n = next(dstream), next(dstream)
            print "%.2f" % (r / sin(pi / (2*n)))
    except ZeroDivisionError:
        pass

main()
