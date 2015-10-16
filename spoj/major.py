from sys import stdin
from itertools import imap

def main():
    inp = stdin.readlines()
    for _ in xrange(int(inp[0])):
        h = [0]*2001
        m = 0
        mi = 0
        for x in imap(int, inp[2*_ + 2].split()):
            try:
                h[x + 1000] += 1
                if m < h[x + 1000]:
                    m = h[x + 1000]
                    mi = x
            except KeyError:
                h[x] = 1
        if m <= int(inp[2*_ + 1]) // 2:
            print 'NO'
        else:
            print 'YES', mi

main()
