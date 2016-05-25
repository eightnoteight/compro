#!/usr/bin/env python2.7
# coding: utf-8
from sys import stdin
from operator import itemgetter

def generateLogTable(n):
    """
    ::args::
        n ⟶ size of the log table
    ::returns::
        log base 2 table
    ::note::
        using logtable is efficient for large
          number of queries than using math.log approximation.
        math.log easily takes 8 - 20 iteration for each query.
    """
    logt = [0, 0]
    for x in xrange(2, n):
        logt.append(logt[x >> 1] + 1)
    return logt

class rangeMinimumQuery(object):
    """
    rangeMinimumQuery using sparse table approach
    Complexity:
        preprocessing step => O(nlogn)
        query step => O(1)
    """
    def __init__(self, arr):
        self.arr = arr
        n = len(arr)
        self.logt = generateLogTable(n + 1)
        self.rmq = self.generateSparseTable(n, self.logt)

    def __getitem__(self, slx):
        """
        ::args::
            slx ⟶ slice object denoting the range
        ::returns::
            min(arr[i: j])
        """
        i, j, _ = slx.indices(len(self.arr))
        k = self.logt[j - i]
        if self.arr[self.rmq[i][k]] < self.arr[self.rmq[j - (1 << k)][k]]:
            return self.rmq[i][k]
        else:
            return self.rmq[j - (1 << k)][k]

    def query(self, i, j):
        """
        ::args::
            i ⟶ starting index of the range
            j ⟶ ending index of the range (excluded)
        ::returns::
            position of min(arr[i: j])
        """
        k = self.logt[j - i]
        return min(
            self.arr[self.rmq[i][k]],
            self.arr[self.rmq[j - (1 << k)][k]])

    def generateSparseTable(self, n, logt):
        rmq = [[0]*(1 + logt[n]) for _ in xrange(n)]
        for x in xrange(n):
            rmq[x][0] = x
        for x in xrange(n - 1, -1, -1):
            for y in xrange(1, logt[n - x] + 1):
                if self.arr[rmq[x][y - 1]] < self.arr[rmq[x + (1 << (y - 1))][y - 1]]:
                    rmq[x][y] = rmq[x][y - 1]
                else:
                    rmq[x][y] = rmq[x + (1 << (y - 1))][y - 1]
        return rmq


def blah(query, rmq, arr):
    univ = [query]
    answer = []
    for _ in xrange(100):
        mipos = (-1, -1)
        for i, (x, y) in enumerate(univ):
            if mipos[0] == -1 or arr[mipos[0]] > arr[rmq[x: y]]:
                mipos = (rmq[x: y], i)
        if mipos[0] == -1:
            break
        answer.append(arr[mipos[0]])
        split = univ.pop(mipos[1])
        if mipos[0] > split[0]:
            univ.append((split[0], mipos[0]))
        if mipos[0] + 1 < split[1]:
            univ.append((mipos[0] + 1, split[1]))
    return answer



def main():
    mod = 1000000007
    nextint = iter(map(int, stdin.read().split())).next
    for _ in xrange(nextint()):
        q, k = nextint(), nextint()
        b = [nextint() for _ in xrange(k)]
        c = [nextint() for _ in xrange(k)]
        queries = [(nextint() - 1, nextint()) for _ in xrange(q)]
        n = max(max(queries, key=itemgetter(1))[1], k)
        arr = b + ([0] * (n - k))
        for x in xrange(k, n):
            for y in xrange(k):
                arr[x] += c[y] * arr[x - y - 1]
            arr[x] %= mod
        rmq = rangeMinimumQuery(arr)
        out = []
        for qu in queries:
            out.append(' '.join(map(str, blah(qu, rmq, arr))))
            # out.append(' '.join(map(str, sorted(arr[qu[0]: qu[1]])[:100])))
        print '\n'.join(out)

main()
