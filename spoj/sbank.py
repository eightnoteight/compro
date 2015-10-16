#!/usr/bin/env python
# -*- encoding: utf-8 -*-

def main():
    from sys import stdin

    inp = iter(stdin.readlines())
    for _ in xrange(int(next(inp))):
        n = int(next(inp))
        acc = {}
        for x in xrange(n):
            n = next(inp).strip()
            try:
                acc[n] += 1
            except:
                acc[n] = 1
        for x in sorted(acc.iterkeys()):
            print x, acc[x]
        print
        next(inp)


if __name__ == '__main__':
    try:
        main()
    except:
        pass
