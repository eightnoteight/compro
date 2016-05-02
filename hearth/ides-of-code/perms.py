from sys import stdin
from itertools import permutations
def main():
    next = iter(stdin.read().split()).next
    for _ in xrange(int(next())):
        w, c = next().strip(), next().strip()
        if c not in w:
            continue
        loc = w.find(c)
        for perm in permutations(w[:loc] + w[loc + 1:]):
            print c + ''.join(perm)

main()
