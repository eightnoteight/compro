#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,bad-builtin,missing-docstring


def main():
    def maximum_subarray_sum(A):
        s = 0
        m = 0
        count = 0
        for x in A:
            s += x
            if s < 0:
                s += 1
            if m < s:
                m = s
        return m, count
    for _ in xrange(int(raw_input())):
        raw_input()
        A = map(int, raw_input().split())
        ans = maximum_subarray_sum(A)
        print ans[0], ans[1]

main()
