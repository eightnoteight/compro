from sys import stdin
from itertools import groupby
from operator import itemgetter
from heapq import heappop, heappush


def main():
    nextint = iter(map(int, stdin.read().split())).next
    # next = iter(stdin.read().split()).next
    nk, q = nextint(), nextint()
    temp = 0
    Qu = [(nextint(), nextint() + 1, nextint()) for _ in xrange(q)]
    ends = []
    temps = {}
    for k, it in groupby(sorted(Qu), key=itemgetter(0)):
        while ends and ends[0][0] <= k:
            e = heappop(ends)
            temp -= e[1]
            temps[e[0]] = temp
        for _, y, i in it:
            temp += i
            heappush(ends, (y, i))
        temps[k] = temp
    while ends:
        e = heappop(ends)
        temp -= e[1]
        temps[e[0]] = temp
    assert temp == 0
    tot = 0
    xxx = sorted(temps.items())
    for (x1, y1), (x2, y2) in zip(xxx, xxx[1:]):
        if y1 >= nk:
            tot += x2 - x1
    print tot

main()
