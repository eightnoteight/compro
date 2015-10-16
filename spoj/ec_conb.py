#!/usr/bin/env python
# -*- encoding: utf-8 -*-

for _ in xrange(int(raw_input())):
    t = int(raw_input())
    if t % 2:
        print t
    else:
        print int(bin(t)[-1:1:-1], 2)
