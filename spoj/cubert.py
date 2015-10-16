#!/usr/bin/python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
from sys import stdin
from itertools import imap

def nraph(n):
    n *= 10**60
    lo, hi = 0, 10**200
    for _ in xrange(700):
        mid = lo + ((hi - lo) / 2)
        k = mid*mid*mid
        if k == n:
            num = str(mid)
            return num[:-20] + '.' + num[-20:]
        elif k > n:
            hi = mid
        else:
            lo = mid + 1
    num = str(lo)
    return num[:-20] + '.' + num[-20:]

def main():
    dstream = imap(int, stdin.read().split())
    for _ in xrange(next(dstream)):
        ans = nraph(next(dstream))[:-10]
        print sum(map(int, ans.replace('.', '0'))) % 10, ans

main()
