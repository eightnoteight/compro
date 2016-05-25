def main():
    bulbs = raw_input().strip()
    dp = [[0]*26]
    for ch in bulbs:
        dp.append(dp[-1][:])
        dp[-1][ord(ch) - ord('a')] += 1
    # print dp

    for _ in xrange(int(raw_input())):
        l, r = map(int, raw_input().split())
        # print dp[r]
        counts = [x - y for x, y in zip(dp[r], dp[l - 1])]
        print sum([x - (x % 2) for x in counts]) + any([x % 2 for x in counts])

main()
