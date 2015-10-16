#!/usr/bin/env python

from sys import stdin

def main():
    inp = map(int, stdin.read().split())
    for x in xrange(len(inp) // 2 - 1):
        print inp[2*x]**inp[2*x + 1]

main()
