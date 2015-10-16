#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# pylint: disable=C0111
from collections import defaultdict
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
    n = len(s)
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
    raw_input = input
    while True:
        n = int(raw_input())
        if not n:
            break
        s = raw_input()
        print(maxlen(s, n))


main()
