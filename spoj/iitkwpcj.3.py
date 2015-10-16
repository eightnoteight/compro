#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
import sys
# sys.stdin = open('/tmp/spojtest.in', 'r')


def main():
    def yesorno(s1, s2):
        if s1 == s2:
            return True
        n1, n2 = len(s1), len(s2)
        status = False
        if n1 > n2:
            s1, s2 = s2, s1
            n1, n2 = n2, n1
        status = s2[:n1*(n2 // n1)] == s1*(n2 // n1)
        if status and n2 % n1:
            # print(s1, s2, s2[-(n2 % n1):])
            status = yesorno(s1, s2[-(n2 % n1):]) and yesorno(s2, s2[-(n2 % n1):])
        return status


    dstream = iter(sys.stdin.read().split())
    for _ in range(int(next(dstream))):
        print('YES' if yesorno(next(dstream), next(dstream)) else 'NO')



main()
