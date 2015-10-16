#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
from sys import stdin

def main():
    dstream = iter(stdin.read().split())
    for _ in xrange(int(next(dstream))):
        next(dstream)
        s = iter(next(dstream))
        keys = {x:0 for x in 'abcdefghijklmnopqrstuvwxyz'}
        count = 0
        for k, c in zip(s, s):
            keys[k] += 1
            if keys[c.lower()] > 0:
                keys[c.lower()] -= 1
            else:
                count += 1
        print count

main()
