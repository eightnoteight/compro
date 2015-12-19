from sys import stdin

def zrbrec(n, m, z, r, b):
    if n == 0:
        return 0
    if b == 0:
        return min(z + r, n*m)
    else:
        return r + 1 + zberec(n - 1, m, z, b - 1, m - r - 1)

def zbrec(n, m, z, b):
    if n == 0:
        return 0
    if b == 0:
        return min(n*m, z)
    else:
        eachrowbs = (m + 1) // 2
        totbs = min(n*eachrowbs, b)
        return totbs + min(n*m - totbs, z)


def zberec(n, m, z, b, e):
    if e == 0:
        assert False
        return zbrec(n, m, z, b)
    if b == 0:
        return min(z, e + n*m)
    esegmentbs = min(b, e // 2)
    esegempty = e - esegmentbs
    b -= esegmentbs
    if b == 0:
        return esegmentbs + min(esegempty + n*m, z)
    else:
        return esegmentbs + min(esegempty, z) + zbrec(n, m, max(0, z - esegempty), b)

def recn1(_, m, z, l, r, b):
    if b == 0:
        return min(l + r + z, m)
    else:
        lrs = l + r
        m = m - lrs
        bs = min((m + 1) // 2, b)
        return lrs + bs + min(m - bs, z)

def recn2(_, m, z, l, r, b):
    if b == 0:
        return min(l + r + z, 2*m)
    elif l + 1 + r > m:
        rs = r - (m - l - 1)
        bs = min(b - 1, (m - rs + 1) // 2)
        return m + rs + bs + min(m - rs - bs, z)
    else:
        lrs = l + 1 + r
        empty = m - lrs
        bs = min(empty // 2, b - 1)
        return lrs + bs + min(empty - bs, z) + zbrec(1, m, z - min(empty - bs, z), b - bs)

def sprec(n, m, z, l, r, b):
    assert l < m - 1 and r < m - 1 and m % 2 == 0 and b != 0 and n != 0
    if l + 1 + r > m:
        if n == 1:
            return m
        nn = n - 2
        nn, l = nn - min(nn, l), l - min(nn, l)
        nn, r = nn - min(nn, r), r - min(nn, r)
        lrs = n - 2 - nn
        bs = min((n - 2)*(m // 2), b - 1)
        empty = (n - 2)*m - lrs - bs
        return lrs + bs + min(empty, z) + recn2(2, m, max(0, z - empty), l, r, b - bs)
    elif l + 1 + r <= m:
        nn = n - 1
        nn, l = nn - min(nn, l), l - min(nn, l)
        nn, r = nn - min(nn, r), r - min(nn, r)
        lrs = n - 1 - nn
        bs = min((n - 1)*(m // 2), b - 1)
        empty = (n - 1)*m - lrs - bs
        return lrs + bs + min(empty, z) + recn1(1, m, max(0, z - empty), l, r, b - bs)

def rec(n, m, z, l, r, b):
    lm1blocks = l // (m - 1)
    lm1bcount = min(b, lm1blocks)
    l -= lm1bcount*(m - 1)
    b -= lm1bcount
    rm1blocks = r // (m - 1)
    rm1bcount = min(b, rm1blocks)
    r -= rm1bcount*(m - 1)
    b -= rm1bcount
    blockcount = lm1bcount + rm1bcount
    # print '1:', blockcount, lm1bcount, rm1bcount, l, r, b
    if blockcount >= n:
        return n*m
    elif b == 0:
        return min(n*m, blockcount*m + l + r + b + z)
    else:
        if m % 2 == 0:
            return blockcount*m + sprec(n - blockcount, m, z, l, r, b)
        bigbblock = min(m, l + 1 + r)
        r -= bigbblock - l - 1
        l = 0
        b -= 1
        if bigbblock == m:
            blockcount += 1
            return blockcount*m + zrbrec(n - blockcount, m, z, r, b)
        else:
            assert l == 0 and r == 0
            return blockcount*m + bigbblock + zberec(n - blockcount - 1, m, z, b, m - bigbblock)


def main():
    nextint = iter(map(int, stdin.read().split())).next
    for _ in xrange(nextint()):
        n, m, z, l, r, b = [nextint() for _ in xrange(6)]
        if b == 0 or m == 1:
            print min(n*m, l + r + z + b)
        else:
            print rec(n, m, z, l, r, b)

main()
