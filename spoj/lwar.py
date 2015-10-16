#!/usr/bin/python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin,star-args
from sys import stdin


def main():
    out = bytearray()
    dstream = iter(stdin.read().split())
    for _ in xrange(int(next(dstream))):
        ship = list(next(dstream))
        for i, x in enumerate(ship):
            if '01'[i % 2] == x:
                if i % 2:
                    for y in xrange(i, len(ship)):
                        ship[y] = '01'[ship[y] == '0']
                break
            elif i % 2:
                ship[i] = '01'[ship[i] == '0']
        out.extend(''.join(ship))
        out.append('\n')
    print out

main()
