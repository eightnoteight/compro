from sys import stdin


def main():
    mod = 1000000007
    def tots(b, e):
        return (pow(b, e + 1, mod) - 1) * pow(b - 1, mod - 2, mod)
    def imod(x):
        return pow(x, mod - 2, mod)
    factors = [[] for _ in xrange(1000001)]
    for x in xrange(2, 1000001):
        if not factors[x]:
            for y in xrange(x, 1000001, x):
                k, t = 0, y
                while t % x == 0:
                    t //= x
                    k += 1
                factors[y].append((x, k))
    nextint = iter(map(int, stdin.read().split())).next
    divsum = 1
    nfactors = [0]*1000001
    n, q = nextint(), nextint()
    for x, c in factors[n]:
        divsum = (divsum * imod(tots(x, nfactors[x])) * tots(x, nfactors[x] + c)) % mod
        nfactors[x] += c
    for _ in xrange(q):
        x = nextint()
        for f, c in factors[x]:
            divsum = (divsum * imod(tots(f, nfactors[f])) * tots(f, nfactors[f] + c)) % mod
            nfactors[f] += c
        print divsum

main()
