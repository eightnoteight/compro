
def main():
    for _ in xrange(int(raw_input())):
        n = int(raw_input())
        wins = {}
        for x in xrange((n*(n - 1)) // 2):
            a, b = map(int, raw_input().split())
            try:
                wins[a].add(b)
            except KeyError:
                wins[a] = set((b,))

        for x in xrange(1, n + 1):
            try:
                wins[x]
            except KeyError:
                wins[x] = set()

        for player in wins:
            for loser in wins[player]:
                wins[player] = wins[player].union(wins[loser])

        ml = float('-inf')
        mp = None
        for player in wins:
            tmp = len(wins[player])
            if tmp == n:
                tmp -= 1
            if tmp > ml:
                ml = tmp
                mp = player
            elif tmp == ml and player < mp:
                mp = player
        print mp, ml


main()
