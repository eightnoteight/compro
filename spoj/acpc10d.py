#!/usr/bin/env python
# -*- encoding: utf-8 -*-

def main():
    def minpath1(trigraph, n):
        return min(
            trigraph[0][1] + trigraph[1][1],
            trigraph[0][1] + trigraph[0][2] + trigraph[1][1],
            trigraph[0][1] + trigraph[1][0] + trigraph[1][1])

    def minpath2(trigraph, n):
        if trigraph[n - 1][0] < 0:
            trigraph[n - 2][0] += trigraph[n - 1][0] + trigraph[n - 1][1]
            trigraph[n - 2][1] += trigraph[n - 1][0] + trigraph[n - 1][1]
        else:
            trigraph[n - 2][0] += trigraph[n - 1][1]
            trigraph[n - 2][1] += trigraph[n - 1][1]
        trigraph[n - 2][2] += trigraph[n - 1][1]
        for x in xrange(n - 3, 0, -1):
            trigraph[x][2] += min(trigraph[x + 1][2], trigraph[x + 1][1])
            trigraph[x][1] += min(trigraph[x + 1][0], trigraph[x + 1][1], trigraph[x + 1][2], trigraph[x][2])
            trigraph[x][0] += min(trigraph[x + 1][1], trigraph[x + 1][0], trigraph[x][1])
        return min(
            trigraph[0][1] + trigraph[0][2] + min(trigraph[1][1], trigraph[1][2]),
            trigraph[0][1] + min(trigraph[1]))


    _ = 1
    while True:
        n = int(raw_input())
        if n is 0:
            break
        trigraph = []
        for x in xrange(n):
            trigraph.append(map(int, raw_input().split()))
        if n == 2:
            minpath = minpath1
        else:
            minpath = minpath2
        print '%d. %d' % (_, minpath(trigraph, n))
        _ += 1

main()
