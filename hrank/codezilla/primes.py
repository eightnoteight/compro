n = int(raw_input())
sieve = [0]*100001
sieve[0] = sieve[1] = 1
for x in xrange(2, 100001):
    if sieve[x] == 0:
        sieve[x*x: 100001: x] = [1]*len(xrange(x*x, 100001, x))
print '\n'.join(map(str, [i for i, x in enumerate(sieve) if i <= n and x == 0]))
