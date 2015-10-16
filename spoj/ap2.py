for x in xrange(int(raw_input())):
    k, l, s = map(int, raw_input().split())
    n = (2 * s) // (l + k)
    d = (l - k) // (n - 5)
    a = k - 2*d
    print n
    t = a
    for y in xrange(n):
        print t,
        t += d
