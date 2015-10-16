import fractions
i, j = map(int, raw_input().split())
while i != 0 and j != 0:
    if i == j:
        print 1
    else:
        print (i/fractions.gcd(i, j))*(j/fractions.gcd(i, j))
    i, j = map(int, raw_input().split())
