from sys import stdin

t = map(int, stdin.readlines())

l = t[0]
n = t[0] + t[1]
for x in xrange(8):
    if n > 100:
        break
    l = n
    n +=t[x + 2]
if abs(n - 100) == abs(l - 100):
    print (max(n, l))
elif abs(n - 100) < abs(l - 100):
    print (n)
else:
    print (l)
