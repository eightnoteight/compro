#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
from sys import stdin
from itertools import imap

def main():
    dstream = imap(int, stdin.read().split())
    rects = []
    n = next(dstream)
    totalsum = 0
    for t in xrange(n):
        rects.append((next(dstream), next(dstream)))
        totalsum += 2*(rects[-1][0] + rects[-1][1])
    dp = [
        [(
            rects[0][0], rects[0][1], rects[0][0] + rects[0][1])],
        [(
            rects[0][1], rects[0][0], rects[0][0] + rects[0][1])]]
    for t in xrange(1, n):
        z1 = (
            rects[t][0], rects[t][1],
            rects[t][0] + min(
                2*min(rects[t][1], dp[0][-1][1]) + dp[0][-1][2],
                2*min(rects[t][1], dp[1][-1][1]) + dp[1][-1][2]))
        z2 = (
            rects[t][1], rects[t][0],
            rects[t][1] + min(
                2*min(rects[t][0], dp[0][-1][1]) + dp[0][-1][2],
                2*min(rects[t][0], dp[1][-1][1]) + dp[1][-1][2]))
        dp[0].append(z1)
        dp[1].append(z2)
    print totalsum - min(dp[0][-1][2] + dp[0][-1][1], dp[1][-1][2] + dp[1][-1][1])

main()
