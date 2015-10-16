from sys import stdin
from itertools import groupby, izip

def main():
    inp = stdin.read().split()
    for _ in xrange(int(inp[0])):
        for x, y in izip(groupby(inp[_ + 1]), groupby(reversed(inp[_ + 1]))):
            if x[0] is not y[0]:
                print('NO')
                break
        else:
            print('YES')

main()
