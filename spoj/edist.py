from sys import stdin



def main():
    def edist(X, Y):
        mat = [[0] * (len(Y) + 1) for x in xrange(len(X) + 1)]
        for x in xrange(len(X) + 1):
            mat[x][0] = x
        for x in xrange(len(Y) + 1):
            mat[0][x] = x
        for x in xrange(1, len(X) + 1):
            for y in xrange(1, len(Y) + 1):
                mat[x][y] = min(
                    mat[x - 1][y - 1] + (X[x - 1] != Y[y - 1]),
                    mat[x - 1][y] + 1,
                    mat[x][y - 1] + 1)
        return mat[-1][-1]

    inp = stdin.read().split()
    for x in xrange(int(inp[0])):
        print edist(inp[2*x + 1], inp[2*x + 2])


main()
