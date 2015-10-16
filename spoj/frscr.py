#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# pylint: disable=C0111
from sys import stdin
from heapq import heapify, heappush, heappop

'''input
1
20
2 2
2 3
1 2
'''

class pqueue(object):
    def __init__(self, arr=[]):
        self.heap = arr[:]
        heapify(self.heap)

    def push(self, elem):
        heappush(self.heap, elem)

    def pop(self):
        return heappop(self.heap)

    def top(self):
        return self.heap[0]


def main():
    def max_score(p, Ag, Bg):
        apq = pqueue(zip(Ag, Ag, [2]*len(Ag)))
        bpq = pqueue(zip([0]*len(Bg), Bg, [1]*len(Bg)))
        tasks = 0

        while True:
            d = apq.pop()
            if d[0] >= p:
                break
            apq.push((d[0] + d[1]*d[2], d[1], d[2] + 1))
            w = bpq.pop()
            if max(w[0], d[0]) + w[1]*w[2] < p:
                tasks += 1
                bpq.push((max(w[0], d[0]) + w[1]*w[2], w[1], w[2] + 1))

        return tasks

    inp = stdin.readlines()
    for T in xrange(int(inp[0])):
        p = int(inp[4*T + 1])
        # n, m = map(int, inp[4*T + 2])
        Ag = map(int, inp[4*T + 3].split())
        Bg = map(int, inp[4*T + 4].split())
        print max_score(p, Ag, Bg)


main()
