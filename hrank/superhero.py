from sys import stdin

def main():
    nextint = iter(map(int, stdin.read().split())).next
    for _ in xrange(nextint()):
        n, m = nextint(), nextint()
        powers = [[nextint() for _ in xrange(m)] for _ in xrange(n)]
        bulets = [[nextint() for _ in xrange(m)] for _ in xrange(n)]
        dp = powers[0][:]
        for x in xrange(1, n):
            ndp = [float('inf')]*n
            dprec = (zip(dp, bulets[x - 1]))
            dpns =
            for z in xrange(m):
                ndp[z] = min([dp[y] + max(0, powers[x][z] - bulets[x - 1][y]) for y in xrange(m)])
            dp = ndp
        print min(dp)

main()
# https://www.hackerrank.com/challenges/a-super-hero
