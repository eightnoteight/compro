from sys import stdin
a = map(int, stdin.read().split())
n = a.pop(0)
a.sort(reverse=True)
i = 0
maxbit = (len(bin(a[0])) - 3)
while maxbit >= 0 and i < n:
    while not (a[i] & (1 << maxbit)):
        for x in xrange(i, n):
            if a[x] & (1 <<  maxbit):
                a[x], a[i] = a[i], a[x]
                maxbit += 1
                break
        maxbit -= 1
        if maxbit < 0:
            break
    if maxbit < 0:
        break
    j = i + 1
    while j < n:
        if a[j] & (1 << maxbit):
            a[j] ^= a[i]
        j += 1
    maxbit -= 1
    i += 1
ans = 0
for x in a:
    if ans^x > ans:
        ans ^= x
print ans
