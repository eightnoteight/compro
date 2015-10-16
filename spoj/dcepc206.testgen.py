#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
from random import randint
#import sys
#sys.stdin = open('/tmp/spojtest.in', 'r')


def main():
    t = randint(0, 10)
    print(t)
    for _ in range(t):
        n = randint(1, 10**5)
        for _ in range(n):
            print(randint(0, 10**6), end=' ')
        print()


main()
