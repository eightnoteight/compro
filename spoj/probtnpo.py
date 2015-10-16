#!/usr/bin/env python
# -*- encoding: utf-8 -*-


from sys import stdin

pairs = map(str.split, stdin.readlines())

cache = {1: 1}

l = []
for i, j in pairs:
    mc = 0
    for x in xrange(int(i), int(j) + 1):
        y = x
        while True:
            try:
                c = cache[y] + 1
                break
            except:
                pass
            l.append(y)
            if y % 2:
                y = 3*y + 1
            else:
                y //= 2
        while l:
            cache[l.pop()] = c
            c += 1
        mc = max(mc, c)
    print i, j, mc - 1
