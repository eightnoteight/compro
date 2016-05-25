from operator import mul
from sys import stdin
from operator import xor

def xorsum(arr):
    return reduce(xor, arr)

def matrixMul(m1, m2):
    return map(lambda row: map(lambda *column: xorsum(map(mul, row, column)) % 2, *m2), m1)

def matrixMul1(m1, m2):
    return map(lambda row: map(lambda *column: xorsum(map(mul, row, column)), *m2), m1)

def identity(size):
    size = range(size)
    return [[(i == j)*1 for i in size] for j in size]

def matrixExp(x, p):
    y = identity(len(x))
    while p:
        if p & 1:
            y = matrixMul(y, x)
        x = matrixMul(x, x)
        p /= 2
    return y

def main():
    nextint = iter(stdin.read().split()).next
    n = int(nextint())
    arra = [int(nextint()) for _ in xrange(n)]
    arrb = [int(nextint()) for _ in xrange(n)]
    q = int(nextint())
    matrix = [[0]*(2*n) for _ in xrange(2*n)]
    for x in xrange(n):
        matrix[x][x] = 1
        matrix[x][n + ((x - 1) % n)] = 1
        matrix[x][n + x] = 1
        matrix[x][n + ((x + 1) % n)] = 1
    for x in xrange(n, 2*n):
        matrix[x][x] = 1
        matrix[x][x - n] = 1
        matrix[x][(x - n - 1) % n] = 1
        matrix[x][(x - n + 1) % n] = 1
    matrix = matrixMul1(matrixExp(matrix, q), [[x] for x in arra + arrb])
    # matrix = matrixExp(matrix, 1)
    # print '\n'.join(' '.join(map(str, row)) for row in matrix)
    for _ in xrange(q):
        if filter(None, arra) or filter(None, arrb):
            narra = [arra[i] ^ arrb[i - 1] ^ arrb[i] ^ arrb[(i + 1) % n] for i in xrange(n)]
            narrb = [arrb[i] ^ arra[i - 1] ^ arra[i] ^ arra[(i + 1) % n] for i in xrange(n)]
            arra, arrb = narra, narrb
        else:
            break
    print ' '.join(map(lambda x: str(x[0]), matrix[:n]))
    print ' '.join(map(lambda x: str(x[0]), matrix[-n:]))

main()
