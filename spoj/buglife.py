#!/usr/bin/python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
from sys import stdin
from collections import deque
from itertools import imap, izip

def main():
    def is_suspicious(gender, start, interations, status):
        gender[start] = status
        queue = deque([start])
        while queue:
            node = queue.popleft()
            for mate in interations[node]:
                if gender[mate] is None:
                    gender[mate] = not gender[node]
                    queue.append(mate)
                elif gender[mate] == gender[node]:
                    return True  # suspicious bugs found

    dstream = imap(int, stdin.read().split())
    for t in xrange(1, next(dstream) + 1):
        n, i = next(dstream), next(dstream)
        interations = [[] for _ in xrange(n)]
        for _, a, b in izip(xrange(i), dstream, dstream):
            interations[a - 1].append(b - 1)
            interations[b - 1].append(a - 1)

        arr = [None] * n
        print "Scenario #%s:" % t
        for x in xrange(n):
            if arr[x] is None and is_suspicious(arr, x, interations, True):
                print "Suspicious bugs found!"
                break
        else:
            print "No suspicious bugs found!"

main()
