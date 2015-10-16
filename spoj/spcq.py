#!/usr/bin/env python
# encoding: utf-8


def main():
    for x in xrange(int(raw_input())):
        n = int(raw_input())
        s = sum(map(int, str(n)))
        if n % s:
            print(n + s - n % s)
        else:
            print(n)

main()
