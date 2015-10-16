#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# pylint: disable=C0111
from sys import stdin

# GleanStart
# 4
# 252
# 525
# 16884
# 21347
# GleanEnd

def main():

    def divisible_by7(num):
        r = 0
        for x in num:
            r = (r * 10 + x) % 7
        return r == 0

    inp = stdin.read().split()
    for t in xrange(int(inp[0])):
        num = map(int, inp[t + 1])
        # print num
        if len(num) > 2 and divisible_by7(num):
            s = sum(num)
            if (num[-2]*10 + num[-1]) % 4 == 0 and s % 9 == 0:
                print 'Yes',
            else:
                print 'No',
            if (num[-2]*10 + num[-1]) % 25 == 0 and s % 3 == 0:
                print 'Yes'
            else:
                print 'No'
        else:
            print 'No No'

main()

