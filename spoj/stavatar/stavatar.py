#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
from sys import stdin
from sys import stdout

def main():
    dstream = stdin.readlines()
    n, s1, s2 = int(dstream[0]), bytearray(dstream[1]), bytearray(dstream[2])
    arr = [0]*(n + 1)
    for k in xrange(4, int(dstream[3]) + 4):
        l, r = map(int, dstream[k].split())
        arr[l] += 1
        arr[r + 1] -= 1
    cur_sum = 0
    for x in xrange(n):
        cur_sum += arr[x]
        if cur_sum % 2:
            s1[x], s2[x] = s2[x], s1[x]
    stdout.write(s1)
    stdout.write(s2)

main()
