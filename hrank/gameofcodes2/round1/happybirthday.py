from sys import stdin
nextint = iter(map(int, stdin.read().split())).next
n, k = nextint(), nextint()
arr = sorted([nextint() for _ in xrange(n)])
s = 0
for x in xrange(n):
    if s + arr[x] > k:
        print x
        break
    s += arr[x]
else:
    print n
