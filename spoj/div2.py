#!/usr/bin/python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin

def main():
    def sieve(n):
        arr = [1]*n
        for x in xrange(2, n):
            f = x
            while f < n:
                arr[f] += 1
                f += x
        result = [i if x > 3 else 0 for i, x in enumerate(arr)]
        for x in xrange(2, n / 2 + 2):
            f = x
            while f < n:
                if arr[f] % arr[x] != 0:
                    result[f] = 0
                f += x
        return filter(None, result)

    arr = sieve(1000001)
    for x in arr[107::108]:
        print x

main()
