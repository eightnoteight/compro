
def main():
    mod = 1000000007
    fact = [1]
    ifact = [1]
    for x in range(1, 11011):
        fact.append((fact[-1] * x) % mod)
        ifact.append(pow(fact[-1], mod - 2, mod))
    # print(fact[:10], ifact[:10])
    for _ in range(int(input())):
        n, m = map(int, input().split())
        print((fact[n + 1] * fact[m + 1] * ifact[n - 1] * ifact[m - 1] * ifact[2] * ifact[2]) % mod)

main()
