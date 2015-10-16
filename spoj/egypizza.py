#!/usr/bin/env python
# -*- encoding: utf-8 -*-

def main():
    from math import ceil
    try:
        range = xrange
        input = raw_input
    except NameError:
        pass
    parts = ['1/4', '1/2', '3/4']
    counts = [0, 0, 0]
    for _ in range(int(input())):
        counts[parts.index(input())] += 1
    totpiz = 1  # don't forget the party master!
    totpiz += min(counts[0], counts[2])
    counts[0] -= totpiz - 1
    counts[2] -= totpiz - 1
    totpiz += counts[2]
    totpiz += counts[1] // 2
    if counts[1] % 2:
        totpiz += 1
        if counts[0]:
            counts[0] = max(counts[0] - 2, 0)
    counts[1] = 0
    totpiz += ceil(counts[0] / 4.0)
    print(int(totpiz))

if __name__ == '__main__':
    main()
