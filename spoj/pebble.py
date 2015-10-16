#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
import sys


def main():
    for i, pebble in enumerate(sys.stdin.read().split()):
        curch = 1
        count = 0
        for ch in map(int, pebble):
            if ch == curch:
                curch = 1 - ch
                count += 1
        print 'Game #{}: {}'.format(i + 1, count)

main()
