#!/usr/bin/python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
from sys import stdin

def main():
    dstream = iter(map(int, stdin.read().split()))
    for _ in xrange(next(dstream)):
        s, k = bin(next(dstream))[2:], next(dstream)
        oc, answer = 0, float('-inf')
        for x in xrange(len(s) - 1):
            if oc > k - 1:
                break
            if s[x] == '1':
                pk = min(k - oc - 1, len(s) - x - 2)
                answer = max(
                    answer,
                    int(s[:x] + '0' + '1'*pk + '0'*(len(s) - x - 2 - pk) + '1', 2))
                oc += 1
        print answer if answer != float('-inf') else -1

main()
