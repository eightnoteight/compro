from sys import stdin

nextint = iter(map(int, stdin.read().split())).next
for x in xrange(nextint()):
    n = nextint()
    counter = [0]*10
    for x in xrange(n):
        counter[nextint() % 10] += 1
    print sum([counter[x] - 1 for x in xrange(10) if counter[x] > 1])

