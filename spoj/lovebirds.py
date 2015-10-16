#!/usr/bin/python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
from sys import stdin

def main():
    catalan = [1]
    for x in xrange(1, 1001):
        catalan.append(2*(2*x + 1)*catalan[-1] // (x + 2))
    dstream = iter(map(int, stdin.read().split()))
    print '\n'.join([str(catalan[next(dstream) - 1] % 1908) for _ in xrange(next(dstream))])

main()
