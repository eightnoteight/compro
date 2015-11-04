from sys import stdin
nextint = iter(map(int, stdin.read().split())).next

for _ in xrange(nextint()):
    n = nextint()
    arr = [nextint() for _ in xrange(n)]
    exp = 1
    for x in xrange(1, n):
        if arr[x] == -1:
            exp = 0.5*(exp + 1) + 0.5*exp
    print exp
