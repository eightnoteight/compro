from array import array
from sys import stdin, stdout

inp = stdin.readlines()
s, n = map(int, inp[0].split())
weights = array('L', [0] * n)
costs = array('L', [0] * n)
for x in xrange(n):
    weights[x], costs[x] = map(int, inp[x + 1].split())
dp = array('L', [0] * (s + 1))
for i in range(1, n + 1):
    for j in range(s, 0, -1):
        if weights[i - 1] <= j:
            dp[j] = max(dp[j], dp[j - weights[i - 1]] + costs[i - 1])
stdout.write(str(dp[s]))
