from operator import itemgetter

for t in xrange(1, int(raw_input()) + 1):
    n = int(raw_input())
    arr = sorted(
        zip(
            map(int, raw_input().split()), 
            map(int, raw_input().split()), 
            range(n)), 
        key=lambda x: (x[0] * (100 - x[1]), x[2]))
    print 'Case #%d: %s' % (t, ' '.join(map(str, map(itemgetter(2), arr))))
