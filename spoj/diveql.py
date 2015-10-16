from sys import stdin


def main():
    def extended_gcd(aa, bb):
        lastremainder, remainder = abs(aa), abs(bb)
        x, lastx, y, lasty = 0, 1, 1, 0
        while remainder:
            lastremainder, (quotient, remainder) = \
                remainder, divmod(lastremainder, remainder)
            x, lastx = lastx - quotient * x, x
            y, lasty = lasty - quotient * y, y
        return lastremainder, lastx * (-1 if aa < 0 else 1), \
            lasty * (-1 if bb < 0 else 1)

    def modinv(a, m):
        g, x, y = extended_gcd(a, m)
        if g != 1:
            raise ValueError
        return x % m
    mod = 1000000007
    inp = stdin.readlines()
    for _ in xrange(int(inp[0])):
        n, p = map(int, inp[_ + 1].split())
        de = pow(p, n - 1, mod)
        nu = (de * p - 1) * modinv(p - 1, mod)
        print (nu % mod), (de % mod)

main()
