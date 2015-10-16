#!/usr/bin/python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
from sys import stdin
from itertools import imap

def main():
    mod = 1000000007
    fibs = [0, 1, 1] + [0]*10000001
    for x in xrange(3, 10000001):
        fibs[x] = (fibs[x - 1] + fibs[x - 2]) % mod
    nonfibsgen = [[4, 2, 1], [6, 3, 2], [9, 5, 4], [14, 8, 7]]
    for _ in xrange(44):
        nonfibsgen.append([
            sum(nonfibsgen[-1][:2]),
            nonfibsgen[-1][1] + nonfibsgen[-2][1],
            nonfibsgen[-1][1] + nonfibsgen[-2][1] - 1])
    nonfibsgen.reverse()
    nonfibs = [None]*10000001
    for x in xrange(1, 10000001):
        if nonfibsgen[-1][2] == 0:
            nonfibsgen.pop()
        nonfibs[x] = nonfibsgen[-1][0]
        nonfibsgen[-1][0] += 1
        nonfibsgen[-1][2] -= 1
    dstream = imap(int, stdin.read().split())
    for _ in xrange(next(dstream)):
        n = next(dstream)
        print pow(nonfibs[n], fibs[n], mod)

# import cProfile
# cProfile.run("main()")
main()
