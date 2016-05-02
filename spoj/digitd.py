#!/usr/bin/python3
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin

def main():
    def gcd(a, b):
        while b:
            a, b = b, a % b
        return a

    for x in range(int(input())):
        arr = list(map(int, input().split()))
        print ('Case %s: %s DEGREE' % (x + 1, sum([1 for z in range(3) for y in range(z, 3) if gcd(arr[z], arr[y]) == 1])))


main()
