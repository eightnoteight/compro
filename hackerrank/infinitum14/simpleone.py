from sys import stdin

def matmul(x, y, mod):
    return [
        [(x[0][0]*y[0][0] + x[0][1]*y[1][0]) % mod, (x[0][0]*y[0][1] + x[0][1]*y[1][1]) % mod],
        [(x[1][0]*y[0][0] + x[1][1]*y[1][0]) % mod, (x[1][0]*y[0][1] + x[1][1]*y[1][1]) % mod],
    ]

def modinv(num, prime):
    return pow(num, prime - 2, prime)

def powmat(matrix, exp, mod):
    powmatrix = [[1, 0], [0, 1]]
    if exp == 1:
        return matrix
    elif exp % 2:
        res = powmat(matrix, exp // 2, mod)
        powmatrix = matmul(matmul(res, res, mod), matrix, mod)
    elif exp:
        res = powmat(matrix, exp // 2, mod)
        powmatrix = matmul(res, res, mod)
    return powmatrix


def main():
    nextint = iter(map(int, stdin.read().split())).next
    for _ in xrange(nextint()):
        p, q, n = nextint(), nextint(), nextint()
        mp = powmat([[q, p], [-p, q]], n, 1000000007)
        print (mp[0][1]*modinv(mp[1][1], 1000000007)) % 1000000007

main()



# tan(nx) = (tan[(n-1)x]+tanx)/(1-tan[(n-1)x]tanx).
#         = (p1q + q1p) / (q1q - p1p)

# f(x) = f(x - 1)*q + g(x - 1)*p
# g(x) = g(x - 1)*q - f(x - 1)*p
# """
# [ f(x) ]  =  [  q   p ] * [ f(x - 1) ]
# [ g(x) ]  =  [ -p   q ] * [ g(x - 1) ]

#           = [q   p]**(x - 1)   *   [p]
#             [-p  q]                [q]
# """
