from sys import stdin
import numpy as np

def genmat(n, m):
    mat = []
    for x in xrange(n):
        for y in xrange(m):
            mat.append([])
            for i in xrange(n):
                for j in xrange(m):
                    mat[-1].append(int(abs(x - i) + abs(y - j) <= 1))
    print mat
    return np.matrix(mat)**-1

def main():
    nextitem = iter(stdin.read().split()).next
    n, m = int(nextitem()), int(nextitem())
    t = 0
    while n and m:
        vecmat = genmat(n, m)
        mat = []
        for _ in xrange(n):
            mat.extend(map(int, nextitem().replace('X', '1').replace('.', '0')))
        xmat = (np.matrix(mat)*vecmat).tolist()
        t += 1
        n, m = int(nextitem()), int(nextitem())
        print n, m


main()
