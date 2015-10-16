#!/usr/bin/python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
from sys import stdin
from itertools import imap

def main():
    dstream = imap(int, stdin.read().split())
    for _ in xrange(next(dstream)):
        arr = sorted([next(dstream) for _ in xrange(next(dstream))])
        count = 0
        for x in xrange(len(arr)):
            for y in xrange(len(arr)):
                if arr[x] == 2*arr[y]:
                    arr[x] = arr[y] = -1
                    count += 1
        print count

main()
