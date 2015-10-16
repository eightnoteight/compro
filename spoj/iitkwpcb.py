from fractions import gcd
for testcases in xrange(int(raw_input())):
    # problem solution
    n = int(raw_input())
    j = n//2 or 1
    while gcd(j, n) != 1:
        j -= 1
    print j
