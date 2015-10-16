#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# pylint: disable=C0111

# GleanStart
# 2
# 1 1
# 1 2
# GleanEnd
def main():
    for _ in xrange(int(raw_input())):
        _, b = map(int, raw_input().split())
        print '1.000000' if b % 2 else '0.000000'

main()

