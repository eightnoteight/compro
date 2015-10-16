#!/usr/bin/env python
# -*- encoding: utf-8 -*-
from sys import stdin
from collections import defaultdict


def main():
    stdin.readline()
    s = map(int, stdin)
    efd = []
    abc = []
    count = 0
    for e in s:
        for f in s:
            for d in s:
                efd.append((e + f) * d)
                abc.append(e * f + d)
    efdh = defaultdict(int)
    for x in efd:
        efdh[x] += 1
    for x in abc:
        count += efdh[x]
    print (count)

main()
