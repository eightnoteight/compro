from sys import stdin
from itertools import imap


def main():
    mat = [[1]*4 for x in xrange(10002)]
    mat[-1] = [0]
    for x in xrange(1, 10001):
        mat[x][0] = mat[x - 1][1]
        mat[x][1] = mat[x - 1][0] + mat[x - 1][2]
        mat[x][2] = mat[x - 1][3]
        mat[x][3] = mat[x - 1][1] + mat[x - 1][2]
    stdin.readline()
    print '\n'.join(imap(str, (sum(mat[x - 1]) for x in imap(int, stdin))))

main()
