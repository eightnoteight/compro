from sys import stdin
def main():
    nextint = iter(map(int, stdin.read().split())).next
    n, m, k = nextint(), nextint(), nextint()
    rowup = [(0, -1) for _ in xrange(n)]
    colup = [(0, -1) for _ in xrange(m)]
    for x in xrange(k):
        if nextint() == 1:
            r, v = nextint() - 1, nextint()
            rowup[r] = (v, x)
        else:
            c, v = nextint() - 1, nextint()
            colup[c] = (v, x)

    mout = []
    for x in xrange(n):
        out = []
        for y in xrange(m):
            out.append(rowup[x][0] if rowup[x][1] > colup[y][1] else colup[y][0])
        mout.append(' '.join(map(str, out)))
    print '\n'.join(mout)

main()
