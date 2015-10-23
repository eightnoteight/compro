from sys import stdin
nextint = iter(map(int, stdin.read().split())).next
for _ in xrange(nextint()):
    n, k = nextint(), nextint()
    print ['YES', 'NO'][
        len([x for x in [nextint() for _ in xrange(n)] if x <= 0]) >= k
    ]
