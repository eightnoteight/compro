#!/usr/bin/python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
from sys import stdin

def main():
    dstream = iter(stdin.read().split())
    for _ in xrange(int(next(dstream))):
        n, k, play = next(dstream), next(dstream), next(dstream)
        play, turns = bytearray(play), int(n) - int(k)
        while turns > 0:
            for x in xrange(min(turns, 2)):
                play[play.find('10'[x]) if play.find('10'[x]) >= 0 else play.find('01'[x])] = ' '
            turns -= 2
        print play.replace(' ', '')

main()
