#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
import sys
sys.stdin = open('/tmp/spojtest.in', 'r')


def main():
    dstream = iter(map(int, sys.stdin.read().split()))
    for _ in range(next(dstream)):
        n = next(dstream)
        print('{}/{}'.format(int(round(7.8*n)), int(round(0.2*n))))


main()
