from sys import stdin

def main():
    mod = 1000000007
    fact = [1]
    ifact = [1]
    for x in xrange(1, 10000):
        fact.append((fact[-1] * x) % mod)
        ifact.append(pow(fact[-1], mod - 2, mod))
    def npr(r):
        return [0, 10, 90, 720][r]

    def ncr(n, r):
        if r > n:
            return -1
        return (fact[n] * ifact[n - r] * ifact[r]) % mod
    # next = iter(stdin.read().split()).next
    nextint = iter(map(int, stdin.read().split())).next
    for _ in xrange(nextint()):
        d, u = nextint(), nextint()
        ans = ncr(npr(d), u)
        if ans == -1:
            print -1
        else:
            print (ans * fact[u]) % mod

main()

