#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# pylint: disable=C0111

def main():
    n, m, c = map(int, raw_input().split())
    arr = map(int, raw_input().split())
    minimum = arr[0]
    maximum = arr[0]
    for x in xrange(m):
        if minimum > arr[x]:
            minimum = arr[x]
        if maximum < arr[x]:
            maximum = arr[x]
    if maximum - minimum <= c:
        print x - m
    for x in xrange(m, n):
        pass

main()

