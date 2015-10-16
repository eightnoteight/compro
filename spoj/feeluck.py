from sys import stdin


def main():
    inp = stdin.read().split()
    for x in xrange(int(inp[0])):
        mi = 0
        ml = []
        for y in xrange(10):
            s, n = inp[20*x + 2*y + 1], int(inp[20*x + 2*y + 2])
            if mi < n:
                mi = n
                ml = [s]
            elif mi == n:
                ml.append(s)
        print 'Case #%d:' % (x + 1)
        print '\n'.join(ml)


main()
