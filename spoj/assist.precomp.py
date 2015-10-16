#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin

arr = [1]*34000
for x in xrange(2, 34000):
    if arr[x]:
        open('arr', 'a').write(str(x) + '\n')
        c = 0
        for y in xrange(x + 1, 34000):
            if arr[y]:
                if c == x - 1:
                    arr[y] = 0
                    c = -1
                c += 1
