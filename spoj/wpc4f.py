#!/usr/bin/python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin,star-args
from sys import stdin

def main():
    dstream = iter(map(int, stdin.read().split()))
    for _ in xrange(next(dstream)):
        mat = [[next(dstream), next(dstream), next(dstream)] for _ in xrange(next(dstream))]
        for x in xrange(1, len(mat)):
            for y in xrange(3):
                mat[x][y] += min(mat[x - 1][:y] + mat[x - 1][y + 1:])
        print min(mat[-1])

main()
