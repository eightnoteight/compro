#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,bad-builtin,missing-docstring
'''input
4
1
2
3
6
'''
#from sys import stdin


def main():
    def gcd(a, b):
        while b:
            a, b = b, a % b
        return a

    n = int(raw_input())
    nums = [int(raw_input()) for _ in xrange(n)]
    #print nums
    diff = []
    for x in xrange(1, n):
        diff.append(nums[x] - nums[x - 1])
    #print diff
    cf = gcd(diff[0], diff[1])
    for x in xrange(2, len(diff)):
        cf = gcd(cf, diff[x])
    ans = 0
    for x in diff:
        ans += x // cf

    print ans + 1 - n

main()
