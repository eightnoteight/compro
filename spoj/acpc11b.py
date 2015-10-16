#!/usr/bin/env python
# -*- encoding: utf-8 -*-

def main():
    try:
        range = xrange
        input = raw_input
    except:
        pass
    for _ in range(int(input())):
        m1 = map(int, input().split())
        m1.pop(0)
        m2 = map(int, input().split())
        m2.pop(0)
        m1.sort()
        m2.sort()
        m1l = len(m1)
        m2l = len(m2)
        i = 0
        j = 0
        diff = float('inf')
        while i < m1l and j < m2l:
            diff  = min(diff, abs(m1[i] - m2[j]))
            if m1[i] < m2[j]:
                i += 1
            else:
                j += 1
        print diff

if __name__ == '__main__':
    main()
