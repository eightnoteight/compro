#!/usr/bin/python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
from sys import stdin
from itertools import imap

def main():
    arr = [float('-inf')]
    dstream = imap(int, stdin.read().split())
    arr.extend(sorted([next(dstream) for _ in xrange(next(dstream))]))
    arr.append(float('inf'))
    diffs = []
    for x in xrange(1, len(arr) - 1):
        diffs.append((arr[x] - arr[x - 1], arr[x + 1] - arr[x]))
    calc = [(diffs[0][0], 0 if arr[0] == arr[1] else float('inf'), diffs[0][1])]
    arr.pop(0)
    for x in xrange(1, len(diffs)):
        calc.append((
            diffs[x][0] + calc[x - 1][1],
            min(calc[x - 1]) if (arr[x] == arr[x - 1] or arr[x + 1] == arr[x]) else calc[x - 1][2],
            diffs[x][1] + min(calc[x - 1][:2])
        ))
    print arr[:]
    print calc
    print min(calc[-1])

main()
