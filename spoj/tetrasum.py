#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# pylint: disable=C0111
from sys import stdin
from math import log

stdin = open('input', 'r')


def main():
    mod = 1000000007

    def matmul(mat1, mat2):
        sq = [0] * 16
        for x in xrange(4):
            for y in xrange(4):
                for z in xrange(4):
                    sq[x * 4 + y] = (sq[x * 4 + y] + mat1[x * 4 + z] * mat2[z * 4 + y]) % mod
        return sq
    matpow = [
        (1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1),
        (1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0),
    ]
    for _ in xrange(1, 32):
        matpow.append(matmul(matpow[-1], matpow[-1]))

    def tet_gen(n):
        if n < 3:
            return 0
        elif n == 3:
            return 1
        n -= 3
        mat = matpow[0]
        while n:
            pos = int(log(n, 2))  # bisect(pow2, n) - 1
            mat = matmul(matpow[pos + 1], mat)
            n -= 1 << pos

        return mat[0] % mod
    tet = tet_gen

    def tetrasum(n):
        if n < 3:
            return 0
        elif n == 3:
            return 1
        else:
            return (((tet(n + 1) + 3 * tet(n) + 2 * tet(n - 1) + tet(n - 2)  - 1) % mod)*333333336) % mod

    inp = stdin.readlines()
    out = []
    for _ in xrange(int(inp[0])):
        m, n = map(int, inp[_ + 1].split())
        out.append(str((tetrasum(n) - tetrasum(m - 1)) % mod))
    print '\n'.join(out)

main()
