for _ in xrange(int(raw_input())):
    s = raw_input()
    n = len(s)
    lo = 0
    for i in xrange(1, s):
        if s[i] > s[i - 1]:
            lo = i
    print lo
