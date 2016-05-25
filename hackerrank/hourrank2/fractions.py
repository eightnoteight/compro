n = int(raw_input())
arr = map(int, raw_input().split())

cache = {}
for ai in arr:
    turn = set()
    for bi in xrange(1, ai + 2):
        if ai // bi not in turn:
            try:
                cache[ai // bi].append(bi)
            except KeyError:
                cache[ai // bi] = [bi]
            turn.add(ai // bi)

minsum = float('inf')
for c in cache:
    if len(cache[c]) == n:
        minsum = min(sum(cache[c]), minsum)

print minsum
