

def main():
    def permut(n, k):
        dp = [[0]*(k + 1) for _ in xrange(n)]
        dp[0][0] = 1
        for x in xrange(1, n):
            dp[x][0] = 1
            for y in xrange(1, min(k, (x*(x + 1)) // 2) + 1):
                for z in xrange(min(x + 1, y + 1)):
                    dp[x][y] += dp[x - 1][y - z]

        return dp[n - 1][k]

    for _ in xrange(int(raw_input())):
        print permut(*map(int, raw_input().split()))

main()
