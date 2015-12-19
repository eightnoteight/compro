from sys import stdin

def answer(n, m, z, l, r, b):
    pass

def main():
    nextint = iter(map(int, stdin.read().split())).next
    for _ in xrange(nextint()):
        n, m, z, l, r, b = [nextint() for _ in xrange(6)]
        if b == 0 or m == 1:
            print min(n*m, l + r + z + b)
        else:
            print answer(n, m, z, l, r, b)

main()

def union(p1, p2):
    return p1 + p2 - p1*p2

def survival(k, p):
    def kunion(prob, k):
        cp = 0
        for _ in xrange(k):
            cp = union(cp, prob)
        return cp
    prob = p
    pf = 1
    for _ in xrange(10**9):
        if pf < 0.001:
            break
        prob = p*kunion(prob, k)
        pf *= p

    return prob
