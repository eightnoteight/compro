#!/usr/bin/python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
from sys import stdin
from itertools import imap

def main():
    dstream = imap(int, stdin.read().split())
    for _ in xrange(next(dstream)):
        matrix = [bytearray('O'*101)]
        for x in [next(dstream) for _ in xrange(next(dstream))]:
            if matrix[-1][x] == matrix[-1][x + 1] == 79 and (x == 0 or matrix[-1][x - 1] == 79):
                matrix.append(bytearray('-'*101))
                matrix[-1][x] = 79
                continue
            elif matrix[-1][x + 1] == 45 and matrix[-1][x] != 45:
                x += 1
            elif x != 0 and matrix[-1][x - 1] == 45 and matrix[-1][x] != 45:
                x -= 1
            for y in xrange(len(matrix) - 2, -1, -1):
                if matrix[y][x] == matrix[y][x + 1] == 79 and (x == 0 or matrix[y][x - 1] == 79):
                    matrix[y + 1][x] = 79
                    break
                if matrix[y][x] == 45:
                    pass
                elif matrix[y][x + 1] == 45:
                    x += 1
                elif x != 0 and matrix[y][x - 1] == 45:
                    x -= 1
                assert 1 + 1 == 1

        matrix.reverse()
        matrix.pop()
        x = matrix[-1].find('O')
        y = matrix[-1].find('-', x)
        for line in matrix:
            print line[x: y]


main()
