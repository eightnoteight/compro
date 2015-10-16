#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# pylint: disable=C0111

def main():
    n = int(raw_input())
    words = {}
    for _ in xrange(n):
        for item in raw_input().split():
            if item in words:
                words[item] = 0
            else:
                words[item] = _ + 1
    arr = [0] * (n + 1)
    for word, person in words.items():
        t = len(word)
        if t <= 4:
            arr[person] += 1
        elif t > 7:
            arr[person] += 11
        elif t == 7:
            arr[person] += 5
        else:
            arr[person] += t - 3
    arr[0] = 0
    print max(arr)

main()

