from itertools import combinations

def main():
    n, m = map(int, raw_input().split())
    cm = [raw_input().strip() for _ in xrange(n)]
    mat = [[-2]*m for _ in xrange(n)]
    for y in xrange(m):
        last = -1
        for x in xrange(n):
            if cm[x][y] == '.':
                mat[x][y] = last
            else:
                last = x
    inf, minf = float('inf'), float('-inf')
    maxper = minf
    for r1, r2 in combinations(xrange(n), 2):
        mi, ma = inf, minf
        for ind, x, y in zip(xrange(m), cm[r1], cm[r2]):
            if x == 'x' or y == 'x':
                mi, ma = inf, minf
            elif mat[r1][ind] == mat[r2][ind]:
                if mi > ind:
                    mi = ind
                if ma < ind:
                    ma = ind
                if ma - mi >= 1:
                    per = 2*(ma - mi) + 2*(r2 - r1)
                    if per > maxper:
                        maxper = per
    if maxper == minf:
        print 'impossible'
    else:
        print maxper

main()
