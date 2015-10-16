#!/usr/bin/python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin,star-args
from sys import stdin
from itertools import imap

def main():
    out = bytearray()
    try:
        dstream = imap(int, stdin.read().split())
        for _ in xrange(1000000000):
            n = next(dstream)
            arr = [(0, next(dstream)) for _ in xrange(n)]
            dp = [[(float('inf'), float('inf'))]*x for x in xrange(1, len(arr))]
            dp.append(arr)
            for x in xrange(n - 2, -1, -1):
                for y in xrange(x + 1):
                    lo, hi = y, y + n - x
                    for lhi in xrange(lo + 1, hi):
                        dp[n - (hi - lo)][lo] = min(
                            dp[n - (hi - lo)][lo],

                            (
                                dp[n - (lhi - lo)][lo][0] +
                                dp[n - (hi - lhi)][lhi][0] +
                                (
                                    dp[n - (lhi - lo)][lo][1] *
                                    dp[n - (hi - lhi)][lhi][1]),

                                (
                                    dp[n - (lhi - lo)][lo][1] +
                                    dp[n - (hi - lhi)][lhi][1]) % 100
                            )
                        )
            out.extend(bytes(dp[0][0][0]))
            out.append('\n')
    except StopIteration:
        print out

main()
