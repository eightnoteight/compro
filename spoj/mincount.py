#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
from sys import stdin


def main():
    stdin.readline()
    print '\n'.join([str((h*(h + 1)) // 6) for h in map(int, stdin.read().split())])

main()
