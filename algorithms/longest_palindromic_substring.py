def lpalsubstr(string):
    string = '^' + '#'.join(list(string)) + '$'
    lpals = [1]*len(string)
    cent = 1
    for x in xrange(2, len(string) - 2):
        if cent + lpals[cent] <= x:
            cent = x
        lpals[x] = min(cent + lpals[cent], x + lpals[cent - (x - cent)]) - x
        while string[x + lpals[x]] == string[x - lpals[x]]:
            lpals[x] += 1
        if x + lpals[x] >= cent + lpals[cent]:
            cent = x
    epal, opal = max(lpals[::2]), max(lpals[1::2])
    return max(epal - epal % 2, opal + opal % 2 - 1)

def brute(string):
    from itertools import combinations
    lps = 0
    for x, y in combinations(xrange(len(string) + 1), 2):
        lps = max(lps, (y - x)*(string[x:y] == string[x:y][::-1]))
    return lps

def tests():
    import random
    import itertools
    # from string import ascii_lowercase
    for _ in itertools.repeat(None):
        rs = ''.join(random.choice('ab') for _ in xrange(1000))
        print lpalsubstr(rs), brute(rs)
        assert lpalsubstr(rs) == brute(rs)

tests()
