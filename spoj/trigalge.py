#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
from sys import stdin
from math import sin

def trigagle(a, b, c):
    xpos = 1000000
    xneg = -1000000
    prev = None
    while prev != round((xpos + xneg) / 2.0, 6):
        avg = (xpos + xneg) / 2.0
        favg = a*avg + b*sin(avg) - c
        if favg == 0:
            return round(avg, 6)
        elif favg > 0:
            xpos = avg
        else:
            xneg = avg
        prev = round(avg, 6)
    return prev

def main():
    dstream = map(int, stdin.read().split())
    out = bytearray()
    puts = out.extend
    for t in xrange(dstream[0]):
        puts(b'{:6f}\n'.format(
            trigagle(dstream[3*t + 1], dstream[3*t + 2], dstream[3*t + 3])))
    print out

main()
