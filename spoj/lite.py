#!/usr/bin/env python
# -*- encoding: utf-8 -*-

def main():
    from math import log, ceil
    def count(segt, lo, hi, beg, end, ind):
        if lo >= beg and hi <= end:
            return segt[ind]

        if (lo < beg and hi <= beg) or (lo >= end and hi > end):
            return 0

        mid = lo + (hi - lo) // 2

        return count(segt, lo, mid, beg, end, 2*ind + 1) + \
            count(segt, mid, hi, beg, end, 2*ind + 2)

    def flip(segt, lo, hi, beg, end, ind):
        if hi - lo == 1 and lo >= beg and hi <= end:
            segt[ind] = 1 - segt[ind]
            return segt[ind]

        if (lo < beg and hi <= beg) or (lo >= end and hi > end):
            return segt[ind]

        mid = lo + (hi - lo) // 2

        segt[ind] -= segt[2*ind + 1]
        segt[ind] += flip(segt, lo, mid, beg, end, 2*ind + 1)

        segt[ind] -= segt[2*ind + 2]
        segt[ind] += flip(segt, mid, hi, beg, end, 2*ind + 2)

        return segt[ind]

    n, m = map(int, raw_input().split())
    segt = [0] * (2*pow(2, int(ceil(log(n, 2)))) - 1)
    for x in xrange(m):
        c, l, h = map(int, raw_input().split())
        if c:
            print count(segt, 0, n, l - 1, h, 0)
        else:
            flip(segt, 0, n, l - 1, h, 0)

if __name__ == '__main__':
    main()
