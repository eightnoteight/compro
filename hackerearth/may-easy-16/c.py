from collections import defaultdict
from sys import stdin

def main():
    nextint = iter(map(int, stdin.read().split())).next
    n = nextint()
    scientists = defaultdict(int)
    for _ in xrange(n):
        scientists[nextint()] += 1
    m = nextint()
    maud = [nextint() for _ in xrange(m)]
    msub = [nextint() for _ in xrange(m)]
    y = 0
    for x in xrange(m):
        if scientists[maud[y]] < scientists[maud[x]] or (scientists[maud[y]] == scientists[maud[x]] and scientists[msub[y]] < scientists[msub[x]]):
            y = x
    print y + 1


main()
