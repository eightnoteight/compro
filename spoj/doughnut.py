#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# pylint: disable=C0111

def main():
    for _ in xrange(int(raw_input())):
        c, k, w = map(int, raw_input().split())
        print 'yes' if w * c <= k else 'no'

main()

