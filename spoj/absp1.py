from sys import stdin
from itertools import imap



def main():
    inp = stdin.readlines()
    out = []
    tmp = out.append
    for _ in xrange(int(inp[0])):
        arrsum = 0
        s = 0
        i = 0
        for y in imap(int, inp[2*_ + 2].split()):
            s += (i)*(y) - arrsum
            arrsum += y
            i += 1
        tmp(str(s))
    print '\n'.join(out)


main()
