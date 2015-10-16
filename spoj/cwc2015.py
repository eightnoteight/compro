#!/usr/bin/python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin,star-args

def main():
    def isPossible(ps, cs, picks):
        if cs == hafSum and picks == n // 2:
            return True
        if cs >= hafSum or ps == 0 or remSum[ps] < hafSum - cs or picks >= n // 2:
            return False
        return isPossible(ps - 1, cs + arr[ps - 1], picks + 1) or isPossible(ps - 1, cs, picks)

    for test in xrange(1, int(raw_input()) + 1):
        n = int(raw_input())
        arr = map(int, raw_input().split())
        totSum = sum(arr)
        hafSum = totSum // 2
        if n % 2 == 1 or totSum % 2 == 1:
            print 'Case %s: No' % test
        else:
            print 'Case %s: %s' % (test, 'Yes' if isPossible(n, 0, 0) else 'No')

main()
