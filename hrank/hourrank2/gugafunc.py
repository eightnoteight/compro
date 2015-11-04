dp = [0, 0, 1, ]
cursum = 0
mod = 1000000009

for x in xrange(3, 1000001):
    cursum += dp[-1]
    dp.append((cursum + pow(2, x - 1, mod) - 1) % mod)

print sum(dp[:int(raw_input())]) % mod
