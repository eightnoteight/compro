#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
import sys
sys.stdin = open('/tmp/spojtest.in', 'r')


def main():
    def eulergcd(s1, s2):
        if len(s1) > len(s2):
            s1, s2 = s2, s1
        while s1:
            if s1 == s2:
                return True
            if s2.startswith(s1):
                s2, s1 = s1, s2[len(s1):]
            else:
                s1, s2 = '', ''
            if len(s1) > len(s2):
                s1, s2 = s2, s1
        return s1


    dstream = iter(sys.stdin.read().split())
    for _ in range(int(next(dstream))):
        print('YES' if eulergcd(next(dstream), next(dstream)) else 'NO')



main()
