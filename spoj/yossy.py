#!/usr/bin/python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
from sys import stdin
from itertools import imap

def main():
    def yossy(items, m, k):
        pass
    dstream = imap(int, stdin.read().split())
    soldiers = [(next(dstream), next(dstream)) for _ in xrange(next(dstream))]
    s, k = next(dstream), next(dstream)
    for x in yossy(soldiers, s, k):
        print x

main()
