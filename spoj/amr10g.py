#!/usr/bin/env python
# -*- encoding: utf-8 -*-


def main():
    def ans(h, n, k):
        a = float('inf')
        for x in xrange(n - k + 1):
            a = min(a, h[x + k - 1] - h[x])
        return a
    from sys import stdin
    inp = stdin.readlines()
    for _ in xrange(int(inp[0])):
        print ans(sorted(map(int, inp[2*_ + 2].split())), *map(int, inp[2*_ + 1].split()))

if __name__ == '__main__':
    main()
