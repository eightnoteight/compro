#!/usr/bin/env python
n = int(raw_input())
while n != 0:
    permut = map(int, raw_input().split())
    answer = 'ambiguous'
    for x in xrange(n):
        if permut[permut[x]-1] != x+1:
            answer = 'not ambiguous'
            break
    print answer
    n = int(raw_input())
