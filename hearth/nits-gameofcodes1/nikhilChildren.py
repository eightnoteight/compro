from sys import stdin

def main():
    nextint = iter(map(int, stdin.read().split())).next
    fact = [1]
    mod = 1000000007
    for x in xrange(1, 100001):
        fact.append((fact[-1] * x) % mod)
    for _ in xrange(nextint()):
        k, m = nextint(), nextint()
        n = m - sum([nextint() for _ in xrange(k)])
        if n < 0:
            print 0
        else:
            # print n + k - 1, n,  k
            print (fact[n + k - 1] * pow(fact[k - 1] * fact[n], mod - 2, mod)) % mod

main()
