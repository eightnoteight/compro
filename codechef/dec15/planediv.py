from sys import stdin
from collections import defaultdict

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def main():
    nextint = map(int, stdin.read().split()).__next__
    for _ in range(nextint()):
        n = nextint()
        lines = []
        for _ in range(n):
            a, b, c = nextint(), nextint(), nextint()
            gcdabc = gcd(gcd(a, b), c)
            a, b, c = a // gcdabc, b // gcdabc, c // gcdabc
            lines.append((a, b, c))
        counter = defaultdict(set)
        for a, b, c in lines:
            gcdab = gcd(a, b)
            a, b = a // gcdab, b // gcdab
            if (-a, -b) in counter:
                counter[-a, -b].add((-c) / float(gcdab))
            else:
                counter[a, b].add(c / float(gcdab))
        print(max([len(s) for s in counter.values()]))

main()
