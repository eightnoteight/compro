def nCr(n, r):
    if r > n / 2:
        r = n - r  # // because C(n, r) == C(n, n - r)
    ans = 1
    for i in xrange(1, r + 1):
        ans *= n - r + i
        ans /= i
        ans %= 1000000007
    return ans % 1000000007

testcases = int(raw_input())
raw_input()
for t in xrange(testcases):
    a, b, n = map(int, raw_input().split())
    print(pow(a, pow(nCr(2*n, n, 1000000007), b, 1000000007), 1000000007))
