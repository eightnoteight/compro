#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
import sys
sys.stdin = open('/tmp/spojtest.in', 'r')


def main():
    def get_ans(h, a):
        h += 3
        a += 2
        status = 0
        count = 0
        while h > 0 and a > 0:
            if status == 0 and a > 10:
                h, a = h - 5, a - 10
                status = 1
            elif status == 1 or status == 2:
                h, a = h + 3, a + 2
                status = 0
            else:
                h, a = h - 20, a + 5
                status = 2
            count += 1
        return str(count)

    dstream = sys.stdin.readline
    out = []
    for _ in xrange(int(dstream())):
        h, a = map(int, dstream().split())
        out.append(get_ans(h, a))
    print '\n'.join(out)



main()
