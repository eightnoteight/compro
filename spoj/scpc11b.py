#!/usr/bin/python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
from sys import stdin
from itertools import imap

def main():
    out = bytearray()
    try:
        dstream = imap(int, stdin.read().split())
        while True:
            arr = [0]*1441
            n = next(dstream)
            if n == 0:
                raise StopIteration
            for _ in xrange(n):
                arr[next(dstream)] += 1
            last = 0
            for i, x in enumerate(arr):
                if x:
                    if i - last > 200:
                        out.extend('IMPOSSIBLE\n')
                        break
                    last = i
            else:
                if last != 1422 and 1422 - last > 100:
                    out.extend('IMPOSSIBLE\n')
                else:
                    out.extend('POSSIBLE\n')
    except StopIteration:
        print out

main()
