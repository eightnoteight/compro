from sys import stdin
nextint = iter(stdin.read().split()).next
fact = [1]*1000001
mod = 1000000007
for x in xrange(1, 1000001):
    fact[x] = (fact[x - 1] * x) % mod
for _ in xrange((int(nextint()))):
    n, m = int(nextint()), int(nextint())
    print (fact[n*m - n] * pow(pow(fact[m - 1], n, mod), mod - 2, mod)) % mod
