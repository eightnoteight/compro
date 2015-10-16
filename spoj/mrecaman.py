from sys import stdin
from itertools import imap

def main():
    a = [0]*500002
    a[-1] = ''
    v = [True] * 3012501
    v[0] = False
    for x in xrange(1, 500001):
        if (a[x - 1] - x > 0) and v[a[x - 1] - x]:
            v[a[x - 1] - x] = False
            a[x] = a[x - 1] - x
        else:
            v[a[x - 1] + x] = False
            a[x] = a[x - 1] + x

    for x in imap(lambda y: a[int(y)], stdin):
        print x

main()
