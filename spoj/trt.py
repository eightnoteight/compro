#!/usr/bin/env python
# -*- encoding: utf-8 -*-


def main():
    from sys import stdin

    a = map(int, stdin.read().split())
    n = a.pop(0)
    dp = [x * n for x in a]
    for x in xrange(n - 1, 0, -1):
        for y in xrange(x):
            dp[y] = max(dp[y] + x*a[y + n - x], dp[y + 1] + x*a[y])
    print dp[0]


if __name__ == '__main__':
    main()
