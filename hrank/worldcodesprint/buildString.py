from os.path import commonprefix
from itertools import chain, islice

def getsufarr(A):
    L = sorted((a, i) for i, a in enumerate(A))
    n = len(A)
    count = 1
    while count < n:
        P = [0] * n
        for (r, i), (s, j) in zip(L, islice(L, 1, None)):
            P[j] = P[i] + (r != s)
        L = sorted(chain((((P[i], P[i + count]), i) for i in range(n - count)),
                         (((P[i], -1), i) for i in range(n - count, n))))
        count *= 2
    return [i for _, i in L]

def getcomarr(sufarr, string):
    comarr = [0]*len(string)
    for x in xrange(len(string) - 1):
        comarr[x] = len(commonprefix([string[sufarr[x]:], string[sufarr[x + 1]:]]))
    return comarr

def main():
    for _ in xrange(int(raw_input())):
        n, a, b = map(int, raw_input().split())
        string = raw_input().strip()
        sufarr = getsufarr(string)
        comarr = getcomarr(sufarr, string)
        rules = [x for x in xrange(n)]
        for x in xrange(n - 1):
            mi, ma = min(sufarr[x], sufarr[x + 1]), max(sufarr[x], sufarr[x + 1])
            maxcom = min(ma - mi, comarr[x])
            if maxcom >= 1 and ma - 1 < rules[ma + maxcom - 1]:
                rules[ma + maxcom - 1] = ma - 1
        dp = [a]
        for x in xrange(1, n):
            dp.append(a + dp[-1])
            if rules[x] != x:
                dp[x] = min(dp[x], b + dp[rules[x]])
        print dp[-1]


main()
