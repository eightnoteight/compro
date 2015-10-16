#!/usr/bin/python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
from sys import stdin

def main():
    raw_input = stdin.readline
    out = bytearray()
    outp = out.extend
    for _ in xrange(int(raw_input())):
        n = int(raw_input())
        outp(bytes(n - 1) if sum(map(int, raw_input().split())) % n else bytes(n))
        outp('\n')
    print out

main()
