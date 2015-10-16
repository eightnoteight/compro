from sys import stdin
series = [1]*100002
mod = 1000000007
k = 1
for n in xrange(2, 100002):
    series[n] = ((series[n - 1] << 1) + k) % mod
    k = (k << 1) % mod
inp = map(int, stdin.read().split())
i = 1
for x in xrange(inp[0]):
    t = inp[i]
    i += 1
    print "Case {}: {}".format(x + 1, series[t])
