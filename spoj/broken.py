#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# pylint: disable=C0111
from collections import defaultdict
from sys import stdin
'''input
5
This can't be solved by brute force.
1
Mississippi
0
'''


def maxlen(s, m):
    counter = defaultdict(int)
    i = j = mln = diff = 0
    n = len(s) - 1
    while j < n:
        counter[s[j]] += 1
        if counter[s[j]] == 1:
            diff += 1
            while diff > m:
                counter[s[i]] -= 1
                if counter[s[i]] == 0:
                    diff -= 1
                i += 1
        j += 1
        if mln < j - i:
            mln = j - i

    return mln


def main():
    inp = stdin.readlines()
    inp.pop()
    for x in xrange(len(inp) // 2):
        print maxlen(inp[2*x + 1], int(inp[2*x]))


main()
