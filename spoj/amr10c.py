from sys import stdin, stdout
from itertools import imap
from math import ceil, sqrt

def main():
    w = stdout.write
    def sieve(n):
        numbers = [True]*n
        primes = []
        for x in xrange(2, n):
            if numbers[x]:
                primes.append(x)
                for y in xrange(2*x, n, x):
                    numbers[y] = False
        return tuple(primes)

    primes = sieve(int(ceil(sqrt(10**9 + 1))))
    def factors(n):
        fact = []
        for prime in primes:
            if prime > n:
                break
            c = 0
            while n % prime == 0:
                c += 1
                n /= prime
            if c:
                fact.append((prime, c))
        return fact


    stdin.readline()
    for n in imap(int, stdin.readlines()):
        mc = 1
        cap = int(n**0.5)
        for x in primes:
            if n == 1 or x > cap:
                break
            c = 0
            while n % x == 0:
                c += 1
                n /= x
            mc = max(c, mc)

        w('%s\n' % mc)


main()
