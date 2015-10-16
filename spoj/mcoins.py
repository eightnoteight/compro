#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,bad-builtin,missing-docstring
'''input
2 3 5
3 12 113 25714 88888
'''


def main():
    winners = [True] * 1000021
    k, l, _ = map(int, raw_input().split())

    for x in xrange(1000001):
        winners[x] = not (winners[x - 1] and winners[x - k] and winners[x - l])

    print ''.join(
        'A' if winners[qu] else 'B' for qu in map(int, raw_input().split()))


main()
