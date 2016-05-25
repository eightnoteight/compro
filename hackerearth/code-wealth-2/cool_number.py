from sys import stdin

counter = [0]*100001
for r in xrange(1, 100001):
    last = 0
    s = bin(r)
    while s.find('101', last) != -1:
        last = s.find('101', last) + 1
        counter[r] += 1

nextint = iter(map(int, stdin.read().split())).next
for x in xrange(nextint()):
    r, k = nextint(), nextint()
    print len([x for x in xrange(1, r + 1) if counter[x] >= k])

