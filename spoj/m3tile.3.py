#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
import sys
#sys.stdin = open('/tmp/spojtest.in', 'r')


def main():
    stream = list(map(int, sys.stdin.read().split()))
    stream.pop()
    tile = ['1', '0', '3', '0', '11', '0', '41', '0', '153', '0', '571', '0', '2131', '0', '7953', '0', '29681', '0', '110771', '0', '413403', '0', '1542841', '0', '5757961', '0', '21489003', '0', '80198051', '0', '299303201']
    print('\n'.join(tile[n] for n in stream))


main()
