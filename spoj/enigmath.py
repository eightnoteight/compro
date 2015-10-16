from sys import stdin


def binarygcd(u, v):
    if u == 0:
        return v
    if v == 0:
        return u
    shift = 0
    while ((u | v) & 1) is 0:
        u >>= 1
        v >>= 1
        shift += 1
    while (u & 1) is 0:
        u >>= 1
    while True:
        while (v & 1) is 0:
            v >>= 1
        if u > v:
            u, v = v, u
        v = v - u
        if v is 0:
            break
    return u << shift


inp = map(int, stdin.read().split())
i = 1
for x in xrange(inp[0]):
    a, b = inp[i], inp[i + 1]
    i += 2
    g = binarygcd(a, b)
    print b // g, a // g
