#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
import sys
sys.stdin = open('/tmp/spojtest.in', 'r')


def main():
    def ways(pos, n, openings, closings, forward):
        if (closings > openings) or (n == pos and openings != closings):
            return 0
        if n == pos and openings == closings:
            return 1
        if forward[-1] == n:
            cache = forward.pop()
            result = ways(pos, n + 1, openings + 1, closings, forward)
            forward.append(cache)
            return result
        else:
            return (ways(pos, n + 1, openings + 1, closings, forward) +
                    ways(pos, n + 1, openings, closings + 1, forward))

    dstream = map(int, sys.stdin.read().split())
    for _ in range(next(dstream)):
        n, k = next(dstream), next(dstream)
        forward = [next(dstream) - 1 for _ in range(k)]
        forward.append(2*n + 1)
        forward.reverse()
        print(ways(2*n, 0, 0, 0, forward))

main()
