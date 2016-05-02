def main():
    sigma = lambda x: (x * (x + 1)) // 2
    for _ in xrange(int(raw_input())):
        n = int(raw_input())
        ans = n
        for x in xrange(1, n):
            ans += n * (n // x) - x * sigma(n // x)
            ans %= 1000000007
        print ans

main()
