#!/usr/bin/env python
# -*- encoding: utf-8 -*-
from sys import stdin

def main():
    facSum = [1]*1000001
    facSum[0] = facSum[1] = 0
    for x in xrange(2, 1000001):
        for y in xrange(2*x, 1000001, x):
            facSum[y] += x
    seq = [0, 0]
    for x in xrange(2, 1000001):
        seq.append(seq[-1] + facSum[x])
    dstream = map(int, stdin.readlines())
    for x in xrange(dstream[0]):
        print seq[dstream[x + 1]]


if __name__ == '__main__':
    main()
