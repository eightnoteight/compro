#!/usr/bin/python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
from sys import stdin
from itertools import imap

def main():
    def tug(arr, n):
        cache = set()
        for x in xrange(1, min(2**n, sum(arr))):
            s = sum([arr[i] for i, y in enumerate(reversed(bin(x))) if y == '1'])
            if s in cache:
                return 'YES'
            cache.add(s)
        return 'NO'

    dstream = imap(int, stdin.read().split())
    for _ in xrange(next(dstream)):
        n = next(dstream)
        arr = [next(dstream) for _ in xrange(n)]
        if n >= 100:
            print 'YES'
            continue
        counter = [0]*100
        for x in arr:
            counter[x] += 1
            if counter[x] > 1:
                print 'YES'
                break
        else:
            print tug(arr, n)

main()
