#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
from sys import stdin

def ways(s):
    cur = 0
    n = len(s)
    mod = 1000000007
    for x in xrange(n - 1, -1, -1):
        cur = ((ord(s[x]) + 1 - ord('a'))*(26**(n - 1 - x)) + cur) % mod
    return cur

def main():
    dstream = stdin.read().split()
    mod = 1000000007
    for t in xrange(1, int(dstream[0]) + 1):
        s1, s2 = dstream[2*t - 1], dstream[2*t]
        print 'Case {}: {}'.format(t, (ways(s2) - ways(s1) - 1) % mod)
        # if s1 <= s2:
        # else:
        #     print 'Case {}: {}'.format(t, (pow(26, len(s1), mod) - ways(s1) + ways(s2) - 1) % mod)

main()
