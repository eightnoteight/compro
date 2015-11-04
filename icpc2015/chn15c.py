
def g_mininv(arr):
    dp = [[0]*(len(arr) + 1) for _ in xrange(len(arr) + 1)]
    for x in xrange(len(arr) - 1, -1, -1):
        for y in xrange(x + 1, len(arr) + 1):
            dp[x][y] = min(
                dp[x + 1][y] + len([arr[x] < z for z in arr[:x] + arr[y:]]),
                dp[x + 1][y] + len([arr[x] > z for z in arr[:x] + arr[y:]]),
                dp[x][y - 1] + len([arr[y - 1] < z for z in arr[:x] + arr[y:]]),
                dp[x][y - 1] + len([arr[y - 1] > z for z in arr[:x] + arr[y:]]))
    return dp[0][-1]

print g_mininv(tuple(range(100)) + (100,))
