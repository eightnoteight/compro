#!/usr/bin/env python
# -*- encoding: utf-8 -*-


def main():
    from sys import stdin

    try:
        range = xrange
    except NameError:
        pass


    inp = stdin.readlines()
    iii = 1
    for _ in range(int(int(inp[0]))):
        n, k = map(int, inp[iii].split())
        n -= 1
        t = map(int, inp[iii + 1].split())
        iii += 2
        tex = [-1] * (k + 1)
        cache = {}
        for x in range(k):
            if t[x] < k + 1:
                if t[x] in cache:
                    tex[cache[t[x]]] = -1
                tex[x + 1] = t[x]
                cache[t[x]] = x + 1
        y = 0
        for x in range(k + 1):
            if tex[x] == -1:
                while y in cache:
                    y += 1
                tex[x] = y
                cache[y] = x
        if n < k:
            print(t[n])
        else:
            n -= k
            print(tex[n % (k + 1)])



if __name__ == '__main__':
    main()
