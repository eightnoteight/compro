#!/usr/bin/python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
from re import split
from sys import stdin

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def main():
    bullshit = diff = 0
    uniq = set()
    for s in filter(None, split("[^a-z]", stdin.read().lower())):
        if s == 'bullshit':
            bullshit += 1
            diff += len(uniq)
            uniq = set()
            continue
        uniq.add(s)

    print diff / gcd(diff, bullshit), '/', bullshit / gcd(diff, bullshit)

main()
