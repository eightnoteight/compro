#!/usr/bin/env python
# -*- encoding: utf-8 -*-


def main():
    from sys import stdin
    from array import array

    #try:
    #    range = xrange
    #except:
    #    pass
    def knapsack(weights, costs, W, mat, n):
        for x in xrange(W + 1):
            mat[0][x] = 0
        for x in xrange(1, n + 1):
            mat[x][0] = 0
            for w in xrange(1, W + 1):
                if weights[x - 1] > w:
                    mat[x][w] = mat[x - 1][w]
                else:
                    mat[x][w] = max(mat[x - 1][w], mat[x - 1][w - weights[x - 1]] + costs[x - 1])
        return mat[n][W]

    def dump_knapsack(mat, W, nitems, costs, weights):
        it = nitems
        w = W
        last = mat[nitems][W]
        totwei = 0
        while w > 0 and mat[it][w - 1] == mat[it][w]:
            w -= 1
        while it >= 0 and w >= 0:
            if last != mat[it][w]:
                totwei += weights[it]
                w -= weights[it]
                last = mat[it][w]
            else:
                last = mat[it][w]
            it -= 1
        return totwei

    inp = iter(map(int, stdin.read().split()))
    matrix = [array('l', [0]*502) for x in xrange(102)]
    weights = array('l', [0]*502)
    funs = array('l', [0]*502)
    budget, n = next(inp), next(inp)
    while n or budget:
        for x in xrange(n):
            weights[x], funs[x] = next(inp), next(inp)
        print('{1} {0}'.format(
            knapsack(weights, funs, budget, matrix, n),
            dump_knapsack(matrix, budget, n, funs, weights)))
        budget, n = next(inp), next(inp)

if __name__ == '__main__':
    main()
