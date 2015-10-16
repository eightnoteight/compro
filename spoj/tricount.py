"""
T[n] = (n*(n+1))//2 + ((n - 1)//2)*((n - 1)//2 + 1) + (n - 1)*((n - 1)%2) + T[n - 1]
"""
for testcases in xrange(int(raw_input())):
    n = int(raw_input())
    print((n*(n + 2)*(2*n + 1))//8)
