#!/usr/bin/python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
from sys import stdin

def main():
    dstream = stdin.read().split()
    dstream.pop()
    dstream.pop()
    dstream = iter(dstream)
    for x, y in zip(dstream, dstream):
        cop, c = 0, 0
        for i in xrange(-1, -max(len(x), len(y)) - 1, -1):
            if -i <= len(x) and -i <= len(y):
                c = (ord(x[i]) + ord(y[i]) + c - 96) // 10
            elif -i <= len(x):
                c = (ord(x[i]) + c - 48) // 10
            else:
                c = (ord(y[i]) + c - 48) // 10
            if c:
                cop += 1
        if cop > 1:
            print cop, "carry operations."
        elif cop:
            print cop, "carry operation."
        else:
            print "No carry operation."

main()
