from sys import stdin
from itertools import imap
from math import sqrt, ceil
import random



def main():
    def fermatfactorize(n):
        if n == 1:
            return ['1']
        if is_probable_prime(n):
            return ['1', str(n)]
        stack = [n]
        factors = [1]
        while stack:
            f1, f2 = fermatfactor(stack.pop())
            if is_probable_prime(f1):
                factors.append(f1)
            else:
                stack.append(f1)
            if is_probable_prime(f2):
                factors.append(f2)
            else:
                stack.append(f2)

        factors.sort()
        return imap(str, factors)
    def fermatfactor(n):
        a = int(ceil(sqrt(n)))
        b2 = a*a - n
        while not sqrt(b2).is_integer():
            a += 1
            b2 = a*a - n
        return int(a - sqrt(b2)), int(a + sqrt(b2))
    _mrpt_num_trials = 5  # number of bases to test


    def is_probable_prime(n):
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

    for n in imap(int, stdin):
        print ' x '.join(fermatfactorize(n))

main()
