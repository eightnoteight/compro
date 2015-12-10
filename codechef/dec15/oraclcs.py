from sys import stdin

def lcs(X, Y):
    mat = [[0] * (len(Y) + 1) for x in xrange(len(X) + 1)]
    for x in xrange(1, len(X) + 1):
        for y in xrange(1, len(Y) + 1):
            if X[x - 1] == Y[y - 1]:
                mat[x][y] = mat[x - 1][y - 1] + 1
            else:
                mat[x][y] = max(mat[x - 1][y], mat[x][y - 1])
    return mat[-1][-1]

def main():
    nextitem = iter(stdin.read().split()).next
    for _ in xrange(int(nextitem())):
        strings = [nextitem() for _ in xrange(int(nextitem()))]
        am, bm = 'a'*len(strings[0]), 'b'*len(strings[0])
        print min(
            [lcs(s, am) for s in strings] + \
            [lcs(s, bm) for s in strings])

main()
