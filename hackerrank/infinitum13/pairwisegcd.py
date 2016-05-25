from sys import stdin
from fractions import gcd
from itertools import combinations


def main():
    mod = 1234567891
    nextint = iter(map(int, stdin.read().split())).next
    n, m = nextint(), nextint()
    aarr = [nextint() for _ in xrange(n)]
    barr = [nextint() for _ in xrange(m + 1)]
    polsums = [0]*(m + 1)
    for x, y in combinations(aarr, 2):
        gcdxy, parg = gcd(x, y), 1
        for z in xrange(m + 1):
            polsums[z] = (polsums[z] + parg) % mod
            parg = (parg * gcdxy) % mod
    for x in xrange(m + 1):
        polsums[x] = (polsums[x] * barr[x]) % mod
    print sum(polsums) % mod

main()
