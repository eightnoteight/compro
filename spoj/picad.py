#!/usr/bin/python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin,star-args
from sys import stdin
from collections import defaultdict
from itertools import imap, groupby

def main():
    dstream = imap(int, stdin.read().split())
    for _ in xrange(10):
        cki, cko = next(dstream), next(dstream)
        times = []
        register = defaultdict(int)
        for x in xrange(next(dstream)):
            times.append(next(dstream))
            times.append(next(dstream) + .1)
            register[times[-1]] -= 1
            register[times[-2]] += 1
        times.sort()
        mac, mic, cc = float('-inf'), float('inf'), 0
        for x, _ in groupby(times):
            cc += register[x]
            if cki <= x <= cko:
                mac, mic = max(mac, cc), min(mic, cc)
        print mic, mac


main()
