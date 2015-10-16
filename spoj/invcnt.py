#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
from sys import stdin


def split_inversions(a, lo, hi):
    mid = lo + (hi - lo) // 2
    left, right = a[lo: mid], a[mid: hi]
    i, j, inv, im, jm = 0, 0, 0, mid - lo, hi - mid
    for k in xrange(lo, hi):
        if i == im or j == jm:
            a[k: k + im - i] = left[i:]
            break
        if left[i] > right[j]:
            inv += im - i
            a[k] = right[j]
            j += 1
        else:
            a[k] = left[i]
            i += 1
    # a[mid + j: hi] = right[j:]
    return inv

def inversions(a, l, h):
    inv = 0
    for x in xrange(l + 1, h):
        for y in xrange(x, l, -1):
            if a[y] >= a[y - 1]:
                inv += x - y
                break
            a[y], a[y - 1] = a[y - 1], a[y]
        else:
            inv += x - l
    return inv

def count_inversions(a, l, h):
    if h - l <= 18:
        return inversions(a, l, h)
    mid = l + (h - l) // 2
    inv = count_inversions(a, l, mid)  # left inversions
    inv += count_inversions(a, mid, h)  # right inversions
    if a[mid] < a[mid - 1]:
        inv += split_inversions(a, l, h)  # split inversions
    return inv


def main():
    lines = map(int, stdin.read().split())
    out = []
    puts = out.append
    i = 1
    for _ in xrange(lines[0]):
        # a = [next(lines) for _ in xrange(next(lines))]
        puts(str(count_inversions(lines, i + 1, i + 1 + lines[i])))
        i += lines[i] + 1
    print '\n'.join(out)


main()
