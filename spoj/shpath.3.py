#!/usr/bin/env python3
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
from heapq import heappush as pqpush
from heapq import heappop as pqpop
import sys
sys.stdin = open('/tmp/spojtest.in', 'r')


def dijkstra(src, graph, maindest):
    route = [float('inf')]*len(graph)
    pqueue = [(0, src, src)]  # a trick here
    while pqueue:
        #print(route)
        weight, src, dest = pqpop(pqueue)
        if dest == maindest:
            return min(route[dest], weight)
        if route[dest] > weight:
            route[dest] = weight
            for ndest, ndweig in graph[dest]:
                pqpush(
                    pqueue,
                    (
                        route[dest] + ndweig,
                        dest,
                        ndest))



def main():
    for _ in range(int(input())):
        citydb = {}
        graph = []
        n = int(input())
        for city_id in range(n):
            city = input()
            citydb[city] = city_id
            graph.append([])
            for _ in range(int(input())):
                dest, weight = map(int, input().split())
                graph[-1].append((dest - 1, weight))
        for _ in range(int(input())):
            src, dest = input().split()
            print(dijkstra(citydb[src], graph, citydb[dest]))



main()
