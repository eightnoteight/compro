
def main():
    mod = 1000000007
    fact = [1]
    ifact = [1]
    for i in xrange(1, 1111):
        fact.append((fact[-1] * i) % mod)
        ifact.append(pow(fact[-1], mod - 2, mod))
    def choose(n, r):
        return (fact[n] * ifact[n - r] * ifact[r]) % mod
    for _ in xrange(int(raw_input())):
        n, m = map(int, raw_input().split())
        print choose(n + m, n)

main()
