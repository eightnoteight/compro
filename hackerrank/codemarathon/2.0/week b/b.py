import sys

def shash(s):
    hs = [0]
    t32 = 2**32
    for ch in s:
        hs.append((hs[-1] * 101 + ord(ch)) % t32)
    return hs

def s2hash(s):
    hs = [0]
    t32 = 1000000007
    for ch in s:
        hs.append((hs[-1] * 10007 + ord(ch)) % t32)
    return hs

def main():
    next = iter(sys.stdin.read().split()).next
    # nextint = iter(map(int, sys.stdin.read().split())).next
    for _ in xrange(int(next())):
        a, b = next(), next()
        ha = shash(a)
        hb = shash(b)
        print ha
        print hb
        m = 0
        t32 = 2**32
        for x in xrange(1, min(len(ha), len(hb))):
            if hb[x] == (ha[-1] - ha[-x - 1] * pow(101, x, t32)) % t32:
                m = max(m, x)
        print a + b[m:]

main()
