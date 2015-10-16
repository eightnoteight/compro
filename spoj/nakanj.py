#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# pylint: disable=C0111
from collections import deque
from sys import stdin

'''input
3
a1 h8
a1 c2
h8 c3
'''


def main():
    def bfs(initial, final):
        queue = deque([initial, None])
        count = 0
        while len(queue) > 1:
            node = queue.popleft()
            if node == final:
                break
            if node is None:
                count += 1
                queue.append(None)
                continue
            i, j = node
            for x, y in ((i - 1, j - 2),
                         (i - 2, j - 1),
                         (i - 2, j + 1),
                         (i - 1, j + 2),
                         (i + 1, j + 2),
                         (i + 2, j + 1),
                         (i + 2, j - 1),
                         (i + 1, j - 2)):
                if (0 <= x < 8) and (0 <= y < 8) and board[x][y]:
                    queue.append((x, y))
                    board[x][y] = False
        return count

    inp = stdin.readlines()
    for t in xrange(int(inp[0])):
        p1, p2 = inp[t + 1].split()
        board = [[True]*8 for _ in xrange(8)]
        print bfs(
            (ord(p1[0]) - ord('a'), int(p1[1]) - 1),
            (ord(p2[0]) - ord('a'), int(p2[1]) - 1))


main()
