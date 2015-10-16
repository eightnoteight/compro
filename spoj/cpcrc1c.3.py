#!/usr/bin/env python3
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
#stdin = open('/tmp/spojtest.in', 'r')
from sys import stdin


def main():
    def getsum(chars):
        n = len(chars)
        digsum = 0
        for x in range(n):
            digit = int(chars[x]) or 0
            digsum += digit*int(chars[x + 1:] or 0)
            digsum += ((digit*(digit - 1)) // 2)*(10**(n - x - 1))
            digsum += (10**(n - x - 1))*int(chars[:x] or 0)*45
        return digsum

    lines = stdin.readlines()
    lines.pop()
    for line in lines:
        low, high = line.split()
        print((getsum(high) - getsum(low) + sum(map(int, high))))


main()
