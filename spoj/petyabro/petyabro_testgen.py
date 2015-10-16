import random
MILKMENPERCENT = 0
n = random.randint(1, 10**5)
m = random.randint(1, min((n*(n - 1)) // 2, 2*(10**5)))
print n, m
milkmen = []
for _ in xrange(n):
    milkmen.append(0 if random.randrange(100) >= MILKMENPERCENT else 1)
print ' '.join(map(str, milkmen))
for _ in xrange(m):
    u, v = random.randint(1, n), random.randint(1, n - 1)
    if v >= u:
        v += 1
    c = random.randint(1, 10**9)
    print u, v, c

