
import random
from fractions import gcd

_mrpt_num_trials = 5  # number of bases to test


def isprime(n):
    assert n >= 2
    # special case 2
    if n == 2:
        return True
    # ensure n is odd
    if n % 2 == 0:
        return False
    # write n-1 as 2**s * d
    # repeatedly try to divide n-1 by 2
    s = 0
    d = n-1
    while True:
        quotient, remainder = divmod(d, 2)
        if remainder == 1:
            break
        s += 1
        d = quotient
    assert(2**s * d == n-1)

    # test the base a to see whether it is a witness for the compositeness of n
    def try_composite(a):
        if pow(a, d, n) == 1:
            return False
        for i in range(s):
            if pow(a, 2**i * d, n) == n-1:
                return False
        return True  # n is definitely composite

    for i in range(_mrpt_num_trials):
        a = random.randrange(2, n)
        if try_composite(a):
            return False

    return True  # no base tested showed n as composite


def eratosthenes(n):
    multiples = set()
    primes = []
    for i in range(2, n+1):
        if i not in multiples:
            primes.append(i)
            multiples.update(range(i*i, n+1, i))
    return primes


primes = eratosthenes(100001)
primesset = set(primes)


def phi(n):
    if n < 2:
        return 0
    if n in primesset:
        return n - 1
    if (n & 2) == 0:
        m = n >> 1
        return (phi(m) << 1) if (m & 1) else phi(m)
    for m in primes:
        if m > n:
            break
        if n % m:
            continue
        o = n // m
        d = gcd(m, o)
        return ((phi(m)*phi(o)*d) // phi(d)) if d != 1 else (phi(m)*phi(o))


def totientsbelow(N):
    allprimes = primesbelow(N+1)

    def rec(n, partialtot=1, min_p=0):
        for p in allprimes:
            if p > n:
                break
            # avoid double solutions such as (6, [2,3]), and (6, [3,2])
            if p < min_p:
                continue
            yield (p, p-1, [p])
            for t, tot2, r in rec(n//p, partialtot, min_p=p):
                yield (t*p, tot2 * p if p == r[0] else tot2 * (p-1), [p] + r)

    for n, t, factors in rec(N):
        yield (n, t)
'''
for x in xrange(int(raw_input())):
    n = int(raw_input())
    print "Case %d: %d" % (x + 1, (n - phi(n)) + 1)
'''
for x in xrange(100000):
    print totientsbelow(x + 1)
