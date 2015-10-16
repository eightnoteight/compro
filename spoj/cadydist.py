#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
"""input

"""
from sys import stdin


def main():
    gets = stdin.readline
    for _ in xrange(int(gets())):
        gets()
        s = 0
        for x, y in zip(
                sorted(map(int, gets())),  # students
                sorted(map(int, gets()), reverse=True)  # prices
        ):
            s += x*y
        print s


main()
