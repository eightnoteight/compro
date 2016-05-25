from sys import stdin
from itertools import combinations

def main():
    nextitem = iter(stdin.read().split()).next
    n = int(nextitem())
    arr = [nextitem() for _ in xrange(n)]
    for x, y in combinations(arr, 2):
        if x == y[::-1]:
            print len(x), x[len(x) // 2]
            break

main()
