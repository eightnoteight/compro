#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# pylint: disable=C0111
from math import sqrt

def main():
    for _ in xrange(int(raw_input())):
        r1, r2, r3 = map(float, raw_input().split())
        a1 = (r1*r2*r3)/(r1*r2+r2*r3+r3*r1+2*sqrt(r1*r2*r3*(r1 + r2 + r3)))
        print "%.6f" % a1

main()

