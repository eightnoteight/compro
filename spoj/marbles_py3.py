def nCr(n, r):
    if r > (n // 2):
        r = n - r

    k = n
    ans = 1
    while k != (n - r):
        ans *= k
        k -= 1
    from math import factorial
    return ans // factorial(r)

for _ in range(int(input())):
    n, k = map(int, input().split())
    print(nCr(n - 1, k - 1))
