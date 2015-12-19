from sys import stdin
from itertools import groupby

def main():
    nextint = iter(map(int, stdin.read().split())).next
    for _ in xrange(nextint()):
        s = 0
        psum = 0
        for _, it in groupby(sorted([nextint() for _ in xrange(nextint())])):
            k = len(list(it))
            s += k
            psum += s*k
        print psum

main()




