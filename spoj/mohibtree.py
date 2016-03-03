#!/usr/bin/env python3.4
from sys import stdin

def main():
    def sieve(n):
        numbers = [True]*n
        numbers[0: 2] = [False]*2
        numbers[4: : 2] = [False]*len(xrange(4, n, 2))
        for x in xrange(3, n, 2):
            if numbers[x]:
                numbers[x*x: : 2*x] = [False]*len(xrange(x*x, n, 2*x))
        return [i for i, x in enumerate(numbers) if x]

    primes = sieve(10000001)
    nextint = iter(stdin.read().split()).next
    out = []
    for t in range(1, int(nextint()) + 1):
        n = int(nextint())
        for p in primes:
            if n % p == 0:
                out.append('Case #{}: {}'.format(t, ((n // p) - 1)))
                break
        else:
            out.append('Case #{}: 0'.format(t))
    print('\n'.join(out))

main()
