for t in xrange(1, int(raw_input()) + 1):
    r, c, w = map(int, raw_input().split())
    print "Case #{}: {}".format(t, (c // w)*r - (1 - bool(c % w)) + w)
