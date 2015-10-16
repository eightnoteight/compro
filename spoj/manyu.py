#!/usr/bin/python
# -*- encoding: utf-8 -*-
from sys import stdin

def main():
    dstream = iter(stdin.read().split())
    for bits, n in zip(dstream, dstream):
        bits = [None] + list(bits)
        for x in xrange(1, len(bits) + 1):
            if x*x >= len(bits):
                break
            bits[x*x] = '01'[bits[x*x] == '0']
        if bits.count('1') >= int(n):
            print 'kill kauravas!'
        elif bits.count('1') == int(n) - 1:
            print 'save 1 friend and kill kauravas!'
        else:
            print 'save %s friends and kill kauravas!' % (int(n) - bits.count('1'))

main()
