#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
from sys import stdin

def eulerPath(adjMat, entrance):
    if entrance is None:
        for i, x in enumerate(adjMat):
            if sum(x):
                entrance = i
    stack = [entrance]
    while stack:
        node = stack.pop()
        for i, x in enumerate(adjMat[node]):
            if x:
                stack.append(i)
                adjMat[node][i] = False
    for x in adjMat:
        if sum(x):
            return False
    return True



def main():
    dstream = iter(stdin.read().split())
    for _ in xrange(int(next(dstream))):
        indeg = {x:0 for x in 'abcdefghijklmnopqrstuvwxyz'}
        outdeg = {x:0 for x in 'abcdefghijklmnopqrstuvwxyz'}
        adjMat = [[False]*26 for _ in xrange(26)]
        n = int(next(dstream))
        for _ in xrange(n):
            s = next(dstream)
            adjMat[ord(s[0]) - ord('a')][ord(s[-1]) - ord('a')] = True
            outdeg[s[0]] += 1
            indeg[s[-1]] += 1
        entrance = None
        exite = None
        for (chx, x), (chy, y) in zip(sorted(outdeg.items()), sorted(indeg.items())):
            if x - y == 1 and entrance is None:
                entrance = ord(chx) - ord('a')
            elif x - y == -1 and exite is None:
                exite = ord(chy) - ord('a')
            elif x == y:
                pass
            else:
                print 'The door cannot be opened.'
                break
        else:
            if (entrance is not None and exite is not None) and eulerPath(adjMat, entrance):
                print 'Ordering is possible.'
            elif entrance is None and exite is None and eulerPath(adjMat, None):
                print 'Ordering is possible.'
            else:
                print 'The door cannot be opened.'


main()
