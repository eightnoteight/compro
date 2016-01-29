from sys import stdin
mycnt = 0

def matmul(mat1, mat2):
    r1, c1, c2 = len(mat1), len(mat1[0]), len(mat2[0])
    mat3 = [[sum([mat1[x][z]*mat2[z][y] for z in xrange(c1)]) % 1000000000 for y in xrange(c2)] for x in xrange(r1)]
    return mat3


def powmat(matrix, n):
    assert len(matrix) == 24
    result = [[int(x == y) for x in xrange(len(matrix))] for y in xrange(len(matrix))]
    while n:
        if n & 1:
            result = matmul(result, matrix)
        matrix = matmul(matrix, matrix)
        n //= 2
    return result

def main():
    nextint = iter(map(int, stdin.read().split())).next
    for _ in xrange(nextint()):
        a, b, c, d, e, f, g, h, n = [nextint() for _ in xrange(9)]
        matrix = [[0]*24 for _ in xrange(24)]
        matrix[0][a - 1] = matrix[0][10 + b - 1] = matrix[0][10 + c - 1] = \
            matrix[10][10 + e - 1] = matrix[10][f - 1] = matrix[10][g - 1] = \
            matrix[1][0] = matrix[2][1] = matrix[3][2] = matrix[4][3] = \
            matrix[5][4] = matrix[6][5] = matrix[7][6] = matrix[8][7] = \
            matrix[9][8] = matrix[11][10] = matrix[12][11] = matrix[13][12] = \
            matrix[14][13] = matrix[15][14] = matrix[16][15] = matrix[17][16] = \
            matrix[18][17] = matrix[19][18] = 1
        matrix[0][-4] = matrix[0][-3] = matrix[-4][-4] = matrix[-4][-3] = \
            matrix[-3][-3] = d
        matrix[10][-2] = matrix[10][-1] = matrix[-2][-2] = matrix[-2][-1] = \
            matrix[-1][-1] = h
        alpha, beta = [], []
        for x in xrange(0, 11):
            alx = (1 if x < a else alpha[x - a]) + \
                (1 if x < b else beta[x - b]) + \
                (1 if x < c else beta[x - c]) + \
                x*(d**x)
            bex = (1 if x < e else beta[x - e]) + \
                (1 if x < f else alpha[x - f]) + \
                (1 if x < g else alpha[x - g]) + \
                x*(h**x)
            alpha.append(alx)
            beta.append(bex)
        colmat = map(lambda x: [x], alpha[:0:-1] + beta[:0:-1] + [10*(d**10), d**10, 10*(h**10), h**10])
        if n <= 10:
            print alpha[n] % 1000000000, beta[n] % 1000000000
        else:
            resmat = matmul(powmat(matrix, n - 10), colmat)
            print resmat[0][0] % 1000000000, resmat[10][0] % 1000000000
            resmat = matmul(powmat(matrix, n - 11), colmat)
            print resmat[0][0] % 1000000000, resmat[10][0] % 1000000000
            resmat = matmul(powmat(matrix, n - 12), colmat)
            print resmat[0][0] % 1000000000, resmat[10][0] % 1000000000
            resmat = matmul(powmat(matrix, n - 13), colmat)
            print resmat[0][0] % 1000000000, resmat[10][0] % 1000000000
            resmat = matmul(powmat(matrix, n - 9), colmat)
            print resmat[0][0] % 1000000000, resmat[10][0] % 1000000000

main()
