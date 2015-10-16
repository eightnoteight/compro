#!/usr/bin/env python
# -*- encoding: utf-8 -*-

def main():
    from sys import stdin
    inp = map(int, stdin.read().split())
    inpi = 1
    for _ in xrange(inp[0]):
        n, m, D = inp[inpi], inp[inpi + 1], inp[inpi + 2]
        inpi += 3
        ans = 0
        for x in xrange(n):
            ans += (inp[inpi + x] - 1) // D
        inpi += n
        if ans >= m:
            print 'YES'
        else:
            print 'NO'

main()
