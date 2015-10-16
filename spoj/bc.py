#!/usr/bin/python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
from math import log, ceil
from sys import stdin
from itertools import imap

def main():
    def bearHandBreak(n, m, k):
        try:
            return cache[n, m, k]
        except KeyError:
            pass
        if n == 1 and m == 1 and k == 1:
            cache[n, m, k] = 1
            return 1
        if n <= 1 and m <= 1 and k <= 1:
            cache[n, m, k] = 0
            return 0
        if n >= m and n >= k:
            cache[n // 2, m, k] = bearHandBreak(n // 2, m, k)
            cache[n - (n // 2), m, k] = bearHandBreak(n - (n // 2), m, k)
            return cache[n // 2, m, k] + cache[n - (n // 2), m, k]
        if m >= n and m >= k:
            cache[n, m // 2, k] = bearHandBreak(n, m // 2, k)
            cache[n, m - (m // 2), k] = bearHandBreak(n, m - (m // 2), k)
            return cache[n, m // 2, k] + cache[n, m - (m // 2), k]
        if k >= n and k >= m:
            cache[n, m, k // 2] = bearHandBreak(n, m, k // 2)
            cache[n, m, k - (k // 2)] = bearHandBreak(n, m, k - (k // 2))
            return cache[n, m, k // 2] + cache[n, m, k - (k // 2)]

    cache = {}
    dstream = imap(int, stdin.read().split())
    out = bytearray()
    for t in xrange(1, next(dstream) + 1):
        n, m, k = next(dstream), next(dstream), next(dstream)
        out.extend("Case #%s: %s %s\n" % (t, bearHandBreak(n, m, k) - 1, int(ceil(log(n, 2)) + ceil(log(m, 2)) + ceil(log(k, 2)))))
    print out

main()
