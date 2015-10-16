#!/usr/bin/env python
# -*- encoding: utf-8 -*-
from __future__ import print_function

def main():
    try:
        range = xrange
        input = raw_input
    except NameError:
        pass

    for _ in range(int(input())):
        txt, pat = input().split()
        try:
            l = []
            l.append(txt.index(pat))
            while True:
                l.append(txt.index(pat, l[-1] + 1))
        except:
            pass
        if l:
            print(len(l))
            for x in l:
                print(x + 1, end=' ')
            print()
        else:
            print('Not Found')
        print()


if __name__ == '__main__':
    main()
