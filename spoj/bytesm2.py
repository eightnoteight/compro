from array import array
from sys import stdin

table = [array('L', [0]*102) for x in xrange(102)]
room = []
h = 0
w = 0

def _maxtable(x, y):
    if x == h or y == w or y < 0:
        return 0
    if table[x][y]:
        return table[x][y]
    table[x][y] = room[x][y] + max(maxtable(x + 1, y),
                                   maxtable(x + 1, y - 1),
                                   maxtable(x + 1, y + 1))
    return table[x][y]


def maxtable(h, w):
    for x in reversed(xrange(h)):
        for y in xrange(w):
            table[x][y] = room[x][y] + max(table[x + 1][y],
                                           table[x + 1][y -1],
                                           table[x + 1][y + 1])
    return max(table[0])



inputdata = map(int, stdin.read().split())
i = 1
for _ in xrange(inputdata[0]):
    h, w = inputdata[i], inputdata[i + 1]
    i += 2
    room = []
    for x in xrange(h + 1):
        for y in xrange(w + 1):
            table[x][y] = 0
    for row in xrange(h):
        room.append(inputdata[i:i+w])
        i += w
    print maxtable(h, w)
