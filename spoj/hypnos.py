n = int(raw_input())
c = 0
while n >= 10:
    t = n
    n = 0
    c += 1
    while t:
        n += (t % 10) ** 2
        t //= 10
if n == 1:
    print c
elif n == 7:
    print c + 5
else:
    print -1
