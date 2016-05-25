import sys

def atstart(_):
    import atexit
    import cStringIO
    buff = cStringIO.StringIO()
    sys.stdout = buff
    @atexit.register
    def _0_():
        sys.__stdout__.write(buff.getvalue())
    return _

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
    g, x, _ = extended_gcd(a, m)
    if g != 1:
        raise ValueError
    return x % m

@atstart
def main():
    # next = iter(sys.stdin.read().split()).next
    nextint = iter(map(int, sys.stdin.read().split())).next
    mod = 997868736947
    for _ in xrange(nextint()):
        a, b, n = nextint(), nextint(), nextint()
        if a == b:
            print ((n + 1) * pow(a, n + 1, mod)) % mod
        else:
            print ((pow(a, n + 1, mod) - pow(b, n + 1, mod)) * modinv(b - a, mod)) % mod

main()
