#!/usr/bin/python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
from sys import stdin
from collections import deque
from itertools import imap

def main():
    def bfs(graph, src):
        queue = deque([src, None])
        traversal = []
        stage = 0
        while len(queue) > 1:
            node = queue.popleft()
            if node is None:
                stage += 1
                queue.append(None)
                continue
            traversal.append((stage, node))
            if node in graph:
                queue.extend(graph[node])
        return traversal

    dstream = imap(int, stdin.read().split())
    n, m = next(dstream), next(dstream)
    dependencies = dict(
        [(next(dstream) - 1, [next(dstream) - 1 for _ in xrange(next(dstream))]) for _ in xrange(m)])
    rootfilter = [True]*n
    for y in dependencies.values():
        for x in y:
            rootfilter[x] = False
    print rootfilter
    traversal = []
    for i, x in enumerate(rootfilter):
        if x:
            traversal.extend(sorted(bfs(dependencies, i)))
    for x, y in traversal:
        print y + 1,

main()
