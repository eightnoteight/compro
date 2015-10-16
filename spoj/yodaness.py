#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# pylint: disable=C0111

# GleanStart
# 2
# 6
# in the force strong you are
# you are strong in the force
# 6
# or i will help you not
# or i will not help you
# GleanEnd
def _mergedinv(arr, lo, hi, tmp):
    mid = (lo + hi) // 2
    i = lo
    k = lo
    j = mid
    invcnt = 0
    while i < mid and j < hi:
        if arr[i] <= arr[j]:
            tmp[k] = arr[i]
            i += 1
        else:
            tmp[k] = arr[j]
            invcnt += mid - i
            j += 1
        k += 1
    while i < mid:
        tmp[k] = arr[i]
        k += 1
        i += 1
    while j < hi:
        tmp[k] = arr[j]
        k += 1
        j += 1
    arr[lo:hi] = tmp[lo:hi]
    return invcnt

def _inversions(arr, lo, hi, tmp):
    if hi - lo <= 1:
        return 0
    inv = 0
    inv += _inversions(arr, lo, (lo + hi) // 2, tmp)
    inv += _inversions(arr, (lo + hi) // 2, hi, tmp)
    inv += _mergedinv(arr, lo, hi, tmp)
    return inv

def inversions(arr):
    tmp = [0] * len(arr)
    return _inversions(arr, 0, len(arr), tmp)

def main():
    for _ in xrange(int(raw_input())):
        raw_input()
        where_is = {}
        for x, word in enumerate(raw_input().split()):
            where_is[word] = x
        arr = []
        for word in raw_input().split():
            arr.append(where_is[word])
        print inversions(arr)

main()
