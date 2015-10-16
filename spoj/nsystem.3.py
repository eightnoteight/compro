#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
import sys
#sys.stdin = open('/tmp/spojtest.in', 'r')


def main():
    def to_mcxi(number):
        mcxi = []
        for x, c in [(1000, 'm'), (100, 'c'), (10, 'x'), (1, 'i')]:
            if number // x:
                mcxi.append("{}{}".format(
                    (number // x) if (number // x) > 1 else '', c))
            number = number % x
        return ''.join(mcxi)
    def to_decimal(mcxi):
        number = 0
        d = {
            'm': 1000,
            'c': 100,
            'x': 10,
            'i': 1
        }
        for x in range(len(mcxi)):
            if mcxi[x].isalpha():
                if mcxi[x - 1].isdigit():
                    number += d[mcxi[x]]*int(mcxi[x - 1])
                else:
                    number += d[mcxi[x]]
            #print(number, '-------')
        return number

    stream = iter(sys.stdin.read().split())
    for _ in range(int(next(stream))):
        print(to_mcxi(to_decimal(next(stream)) + to_decimal(next(stream))))


main()
