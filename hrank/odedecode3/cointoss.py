from sys import stdin
nextint = iter(stdin.read().split()).next
tosses = [0, 0, 1, 1]
for x in xrange(10000001):
    tosses.append((tosses[-2] + tosses[-1]) % 1000000007)
for _ in xrange((int(nextint()))):
    n = int(nextint())
    print tosses[n]




