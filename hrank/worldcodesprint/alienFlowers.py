
def factprep(func):
    mod = 1000000007
    fact = [1]*1000001
    for x in xrange(1, 1000001):
        fact[x] = (x * fact[x - 1]) % mod
    def newfunc(*args, **kwargs):
        return func(fact, *args, **kwargs)
    return newfunc


@factprep
def ncr(fact, n, r):
    mod = 1000000007
    if r > n:
        return 0
    return (fact[n]*pow(fact[n - r], mod - 2, mod)*pow(fact[r], mod - 2, mod)) % mod


def sumnelem(n, p):
    return ncr(n + p - 1, p - 1)

def main():
    mod = 1000000007
    a, b, c, d = map(int, raw_input().split())
    l = b + d + 1
    if b == 0 == d:
        if a == 0 and c == 0:
            print '2'
        elif a != 0 and c != 0:
            print '0'
        else:
            print '1'
    elif b == d:
        print sum([
            sumnelem(a, (l + 1) // 2)*sumnelem(c, l // 2),
            sumnelem(c, (l + 1) // 2)*sumnelem(a, l // 2)]) % mod
    elif abs(b - d) == 1:
        print (sumnelem(a, l // 2)*sumnelem(c, l // 2)) % mod
    else:
        print '0'

main()

