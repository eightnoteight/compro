#!/usr/bin/python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
from sys import stdin

def main():
    arr, sqrt = [float('inf')]*1001, {}
    for x in xrange(32):
        arr[x*x], sqrt[x*x] = 1, x
    for x in xrange(1001):
        if arr[x] == 1:
            near = x
            continue
        for y in xrange(sqrt[near] + 1):
            if arr[y*y] + arr[x - y*y] < arr[x]:
                arr[x] = arr[y*y] + arr[x - y*y]
    arr = map(bytes, arr)
    stdin.readline()
    print '\n'.join([arr[x] for x in map(int, stdin.readlines())])

main()
