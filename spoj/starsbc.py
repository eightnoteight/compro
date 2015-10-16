from sys import stdin
from math import sqrt
def genprimes(n):
    sieve = range(n)
    for i in xrange(3, int(sqrt(n)) + 1, 2):
        if sieve[i]:
            sieve[i*i: : 2*i] = [0]*len(xrange(i*i, n, 2*i))
    sieve[1] = 0
    return filter(None, sieve)

def main():
    primes = genprimes(2**16)
    def phi_n(n):
        phi, sqrt_n = 1, int(sqrt(n))
        for p in primes:
            if p > sqrt_n:
                break
            k = 0
            while n % p == 0:
                n //= p
                k += 1
            if k > 0:
                phi *= (p**(k - 1))*(p - 1)
        if n > 1:
            phi *= n - 1
        return phi
    print '\n'.join([str(phi_n(n) // 2) for n in map(int, stdin.read().split())])

main()
