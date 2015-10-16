#!/usr/bin/python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
from sys import stdin
from itertools import imap
from bisect import bisect

def main():
    arr = [
        0, 5, 30, 155, 780, 3905, 19530, 97655, 488280, 2441405, 12207030, 61035155, 305175780,
        1525878905, 7629394530, 38146972655, 190734863280, 953674316405, 4768371582030,
        23841857910155, 119209289550780, 596046447753905, 2980232238769530, 14901161193847655,
        74505805969238280, 372529029846191405, 1862645149230957030
    ]
    dstream = imap(int, stdin.read().split())
    for _ in xrange(next(dstream)):
        n = next(dstream) - 1
        wordlength = bisect(arr, n)
        n -= arr[wordlength]
        word = []
        for _ in xrange(wordlength):
            word.append('manku'[n % 5])
            n //= 5
        print ''.join(reversed(word))

main()
