from sys import stdin

def main():
    mod = 1000000007
    def C(d, k):
        return ((pow(d, k + 1, mod) - 1) * pow(d - 1, mod - 2, mod)) % mod
    def D(d, k):
        if k < 0:
            return 0
        if k % 2 == 0:
            return ((pow(d*d, k // 2 + 1, mod) - 1) * pow(d*d - 1, mod - 2, mod)) % mod
        else:
            return (d*(pow(d*d, k // 2 + 1, mod) - 1) * pow(d*d - 1, mod - 2, mod)) % mod
    nextint = iter(map(int, stdin.read().split())).next
    for _ in xrange(nextint()):
        d, k, h = nextint(), nextint(), nextint()
        print (C(d, k) - D(d, k - h - 1)) % mod

main()
