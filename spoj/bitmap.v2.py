from collections import deque
from array import array
from sys import stdin


def d(mat, i, j, n, m):
    mn = m * n
    if mat[i * m + j]:
        return 0
    mark = array('i', [0] * 34225)
    queue = deque([i * m + j, -1])
    mark[i * m + j] += 1
    k = 0
    while True:
        c = queue.popleft()
        if c is -1:
            queue.append(-1)
            k += 1
            continue
        # not at all correct from here,
        # have to consider the t * m positions
        if c % m and not mark[c - 1]:
            if mat[c - 1]:
                return k + 1
            queue.append(c - 1)
            mark[c - 1] += 1
        if (c + 1) % m and not mark[c + 1]:
            if mat[c + 1]:
                return k + 1
            queue.append(c + 1)
            mark[c + 1] += 1
        if 0 <= c + m < mn and not mark[c + m]:
            if mat[c + m]:
                return k + 1
            queue.append(c + m)
            mark[c + m] += 1
        if 0 <= c - m < mn and not mark[c - m]:
            if mat[c - m]:
                return k + 1
            queue.append(c - m)
            mark[c - m] += 1


inp = stdin.readlines()
i = 1
for _ in xrange(int(inp[0])):
    n, m = map(int, inp[i].split())
    mat = []
    for x in xrange(n):
        mat.extend(map(int, list(inp[i + 1 + x].strip())))
    print mat
    for x in xrange(n):
        for y in xrange(m):
            print d(mat, x, y, n, m),
        print
    i += n + 2

# this is improved version of bitmap.py but i'm not sure
# that this is going to be accepted.
