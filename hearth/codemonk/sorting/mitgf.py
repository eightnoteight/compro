from operator import itemgetter
from heapq import heappush, heappop, heapify

for _ in xrange(int(raw_input())):
    n, k = map(int, raw_input().split())
    mat = [map(int, raw_input().split()) for _ in xrange(n)]
    rowsums = map(sum, mat)
    colsums = map(sum, [map(itemgetter(x), mat) for x in xrange(n)])
    map(heapify, (rowsums, colsums))
    discomfort, rx, cx = 0, 0, 0
    for x in xrange(k):
        if rowsums[0] + rx < colsums[0] + cx:
            discomfort += rowsums[0] + rx
            heappush(rowsums, heappop(rowsums) + n)
            cx += 1
        else:
            discomfort += colsums[0] + cx
            heappush(colsums, heappop(colsums) + n)
            rx += 1
    print discomfort
