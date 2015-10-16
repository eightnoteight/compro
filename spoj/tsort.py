from sys import stdin
from itertools import imap


def main():
    stdin.readline()
    a = [0] * 1000001
    for x in imap(int, stdin):
        a[x] += 1
    ans = []
    for x in xrange(1000001):
        ans.extend([str(x)]*a[x])
    print '\n'.join(ans)

main()
