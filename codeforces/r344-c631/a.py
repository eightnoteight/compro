from itertools import combinations

def main():
    n = int(raw_input())
    a = map(int, raw_input().split())
    b = map(int, raw_input().split())
    xa = [a[0]]
    xb = [b[0]]
    for x in xrange(1, n):
        xa.append(a[x] | xa[-1])
        xb.append(b[x] | xb[-1])
    # print xa
    # print xb
    mv = float('-inf')
    for x, y in combinations(xrange(n), 2):
        if x == 0:
            mv = max(mv, xa[y] + xb[y])
        else:
            mv = max(mv, (xa[y] | xa[x - 1]) + (xb[y] | xb[x - 1]))
    print max(mv, a[0] + b[0])

main()
