#!/usr/bin/python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
from sys import stdin
from itertools import imap

def main():
    trngl = [0, 0, 0, 1]
    for x in xrange(4, 1010):
        trngl.append(0)
        for y in xrange(3, x):
            trngl[-1] += trngl[y] * trngl[x - y + 2]
        trngl[-1] %= 100007
    dstream = imap(int, stdin.read().split())
    print '\n'.join([str(trngl[next(dstream) + 1]) for _ in xrange(next(dstream))])

main()
