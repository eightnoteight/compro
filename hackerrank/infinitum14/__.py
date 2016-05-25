from itertools import combinations

def brute():
    for test in xrange(1, int(raw_input()) + 1):
        a, b, k = map(int, raw_input().split())
        cnt = 0
        for x in xrange(a, b + 1):
            if reduce(int.__mul__, map(int, str(x))) == k:
                # print x
                cnt += 1
        print 'Case {}: {}'.format(test, cnt)


brute()
