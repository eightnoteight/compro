from sys import stdin

def rec(n, m, z, l, r, b):
    if n <= 0:
        return 0
    if b == 0:
        return min(n*m, l + z + r)
    if l + z + r >= n*m:
        return n*m
    elif m == 1:
        return min(n*m, l + r + z + b)
    elif m == 2:
        if z >= n*m:
            return n*m
        else:
            if z + l + r >= n*m:
                return n*m
            else:
                zlr = z + l + r
                return zlr + min((n*m - zlr + 1) // 2, b)
    elif m == 3:
        if l == 0 and r == 0:
            bs = min(2*n, b)
            return bs + min(3*n - bs, z)
        if (l == 0 and r == 1) or (r == 0 and l == 1):
            bs = min(2*n, b + 1)
            return bs + min(3*n - bs, z)
        if l + z + r >= n*m:
            return n*m
        else:
            if l == 3:
                return 3 + rec(n - 1, m, z, 0, r, b)
            elif r == 3:
                return 3 + rec(n - 1, m, z, l, 0, b)
            elif l == 2 and r == 1:
                return 3 + rec(n - 1, m, z, l - 2, r - 1, b)
            elif l == 1 and r == 2:
                return 3 + rec(n - 1, m, z, l - 1, r - 2, b)
            elif l == 2 and r == 2:
                return 3 + rec(n - 1, m, z, l - 2, r - 1, b)
            elif l == 0 and r == 2 and b >= 1:
                return 3 + rec(n - 1, m, z, 0, 0, b - 1)
            elif r == 0 and l == 2 and b >= 1:
                return 3 + rec(n - 1, m, z, 0, 0, b - 1)
            elif l == 0 and r == 2 and z >= 1:
                return 3 + rec(n - 1, m, z - 1, 0, 0, b)
            elif r == 0 and l == 2 and z >= 1:
                return 3 + rec(n - 1, m, z - 1, 0, 0, b)
            elif z >= 1 and b >= 2:
                return 3 + rec(n - 1, m, z - 1, l, r, b - 2)
            elif z == 0:
                assert l <= 1 and r <= 1
                if l == 1 and r == 1:
                    return 2 + rec(n - 1, m, 0, 0, 0, b)
                elif l == 1 and r == 0:
                    if b:
                        return 2 + rec(n - 1, m, 0, 0, 0, b - 1)
                    else:
                        return 1
                elif l == 0 and r == 1:
                    if b:
                        return 2 + rec(n - 1, m, 0, 0, 0, b - 1)
                    else:
                        return 1
                elif l == 0 and r == 0:
                    return rec(n, m, 0, 0, 0, b)
                else:
                    raise RuntimeError
            elif b == 1:
                if z >= 1 and l >= 1:
                    return 3 + rec(n - 1, m, z - 1, l - 1, r, b - 1)
                if z >= 1 and r >= 1:
                    return 3 + rec(n - 1, m, z - 1, l, r - 1, b - 1)
                assert l == 0 and r == 0
                return min(n*m, z + b)
            elif b == 0:
                return min(n*m, l + r + z)
    else:
        assert False

def main():
    nextint = iter(map(int, stdin.read().split())).next
    for _ in xrange(nextint()):
        n, m, z, l, r, b = [nextint() for _ in xrange(6)]
        # print n, m, z, l, r, b
        print rec(n, m, z, l, r, b)

main()
