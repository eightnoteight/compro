
def commonprefix(sa, sb):
    if len(sa) > len(sb):
        sa, sb = sb, sa
    for i, x, y in zip(xrange(len(sa)), sa, sb):
        if x != y:
            return i
    return len(sa)

def main():
    for test in xrange(1, int(raw_input()) + 1):
        n, k = map(int, raw_input().split())
        words = sorted([raw_input() for _ in xrange(n)])
        if k == 1:
            print 2*min(map(len, words)) + 1
            continue
        prefix_matches = [0]
        for x in xrange(1, len(words)):
            prefix_matches.append(commonprefix(words[x], words[x - 1]))
        print words
        print prefix_matches
        g_minop = len(words[0]) + 1
        for i in xrange(1, k):
            g_minop += len(words[i - 1]) + len(words[i]) - 2*prefix_matches[i] + 1
        g_minop += len(words[k - 1])
        print 'g_minop =', g_minop
        lop = g_minop
        for i in xrange(k, n):
            lop -= len(words[i - 1])
            lop += len(words[i - 1]) + len(words[i]) - 2*prefix_matches[i] + 1
            lop += len(words[i])
            if i > k:
                lop -= len(words[i - k - 1]) + len(words[i - k]) - 2*prefix_matches[i - k] + 1
            else:
                lop -= len(words[i - k]) + 1
            g_minop = min(g_minop, lop)
        print g_minop




main()
