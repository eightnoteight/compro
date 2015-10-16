for testcases in xrange(int(raw_input())):
    # problem solution
    k = int(raw_input())
    c = (int((8 * k + 1) ** 0.5) - 1) // 2
    if 2 * c == (((8 * k + 1) ** 0.5) - 1):
        c -= 1
    t = k - (c*(c+1) // 2)
    if (c % 2):
        x = t
    else:
        x = c + 2 - t
    y = -x + c + 2
    print 'TERM', k, 'IS', '%s/%s' % (x, y)
