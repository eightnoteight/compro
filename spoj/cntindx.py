from bisect import bisect_left as bisect
from sys import stdin
l = []
d = {}
stdin.readline()
myInput = stdin.readlines()
length = 0
for line in myInput:
    inp = list(map(int, line.split()))
    if inp[0] is 1:
        l.append(inp[1])
        try:
            d[inp[1]].append(length)
        except KeyError:
            d[inp[1]] = [length]
        length += 1
    elif inp[0] is 0:
        try:
            d[l.pop()].pop()
            length -= 1
        except IndexError:
            print('invalid')
    else:
        try:
            print (bisect(d[inp[1]], inp[3]) - bisect(d[inp[1]], inp[2] - 1))
        except KeyError:
            print (0)
