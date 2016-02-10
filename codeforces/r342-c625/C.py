from sys import stdin

def main():
    # nextitem = iter(stdin.read().split()).next
    nextitem = iter(map(int, stdin.read().split())).next
    n, k = nextitem(), nextitem()
    mat = [[0]*n for _ in xrange(n)]
    num = 1
    for x in xrange(n):
        for y in xrange(k - 1):
            mat[x][y] = num
            num += 1
    for x in xrange(n):
        for y in xrange(k - 1, n):
            mat[x][y] = num
            num += 1
    print sum([mat[x][k - 1] for x in xrange(n)])
    print '\n'.join([' '.join(map(str, mat[x])) for x in xrange(n)])

main()

