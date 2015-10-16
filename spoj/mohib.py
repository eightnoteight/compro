#!/usr/bin/python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
from sys import stdin
from itertools import imap

def main():
    dstream = imap(int, stdin.read().split())
    for _ in xrange(next(dstream)):
        x, avg = next(dstream), next(dstream)
        n = avg - x
        print n*(avg + 1) - ((n*(n - 1)) // 2)

main()
