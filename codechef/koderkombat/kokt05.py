from sys import stdin
from collections import defaultdict

def main():
    dstream = iter(stdin.read().split())
    for _ in xrange(int(next(dstream))):
        string = next(dstream)
        counts = defaultdict(int)
        for x in string:
            counts[x] += 1
        print counts
        avg = sum(counts.values()) // len(counts)
        coins = 0
        for v in counts.values():
            coins += abs(avg - v)
        print coins // 2

main()
