from sys import stdin

def main():
    def sieve(n):
        numbers = [True]*n
        primes = []
        for x in range(2, n):
            if numbers[x]:
                primes.append(x)
                for y in range(2*x, n, x):
                    numbers[y] = False
        return primes

    primes = sieve(1001)
    stdin.readline()
    for n in map(int, stdin.readlines()):
        mc = float('-inf')
        for x in primes:
            if n == 1 or x >= n:
                break
            c = 0
            while n % x == 0:
                c += 1
                n /= x
            mc = max(c, mc)
        if n != 1:
            mc = max(1, mc)

        print(mc)


main()
