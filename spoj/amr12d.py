for x in xrange(int(raw_input())):
    s = raw_input()
    print 'YES' if s == s[::-1] else 'NO'
