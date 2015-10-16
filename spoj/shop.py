#!/usr/bin/python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
from sys import stdin
from heapq import heappop, heappush


def main():
    def dijkstra(graph, r, c, sr, sc, dr, dc):
        dist = [[float('inf')]*c for _ in xrange(r)]
        heap = [(0, (sr, sc))]
        while heap:
            nd, (x, y) = heappop(heap)
            if dist[x][y] < nd:
                continue
            dist[x][y] = nd
            if x > 0 and graph[x - 1][y].isdigit():
                heappush(heap, (nd + int(graph[x - 1][y]), (x - 1, y)))
            if x < r - 1 and graph[x + 1][y].isdigit():
                heappush(heap, (nd + int(graph[x + 1][y]), (x + 1, y)))
            if y > 0 and graph[x][y - 1].isdigit():
                heappush(heap, (nd + int(graph[x][y - 1]), (x, y - 1)))
            if y < c - 1 and graph[x][y + 1].isdigit():
                heappush(heap, (nd + int(graph[x][y + 1]), (x, y + 1)))
        return min(
            dist[dr - 1][dc] if dr > 0 else float('inf'),
            dist[dr + 1][dc] if dr < r - 1 else float('inf'),
            dist[dr][dc - 1] if dc > 0 else float('inf'),
            dist[dr][dc + 1] if dc < c - 1 else float('inf')
        )

    gets = iter(stdin.read().split()).next
    while True:
        w, h = int(gets()), int(gets())
        if w == 0 == h:
            break
        graph = [gets() for _ in xrange(h)]
        sc, dc = -1, -1
        for i, x in enumerate(graph):
            if sc == -1:
                sc = x.find('S')
                sr = i
            if dc == -1:
                dc = x.find('D')
                dr = i
            if sc != -1 and dc != -1:
                break
        print dijkstra(graph, h, w, sr, sc, dr, dc)

main()
