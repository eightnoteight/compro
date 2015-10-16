#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# pylint: disable=C0111
from sys import stdin


def main():
    def result(arr):
        arr.append(0)
        arr.append(0)
        for x in xrange(len(arr) - 3, -1, -1):
            if arr[x] + arr[x + 2] > arr[x + 1]:
                arr[x] += arr[x + 2]
            else:
                arr[x] = arr[x + 1]
            # arr[x] = max(arr[x] + arr[x + 2], arr[x + 1])
        return arr[0]

    inp = stdin.readlines()
    for c in xrange(int(inp[0])):
        # if n == 0:
            # raw_input()
            # print "Case %s: %s" % (c + 1, 0)
            # continue

        print "Case %s: %s" % (c + 1, result(map(int, inp[2 * c + 2].split())))


main()



