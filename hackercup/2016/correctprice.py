def main():
    for test in xrange(1, int(raw_input()) + 1):
        n, p = map(int, raw_input().split())
        arr = [0] + map(int, raw_input().split())
        for x in xrange(1, len(arr)):
            arr[x] += arr[x - 1]
        lo, count = 0, 0
        for hi in xrange(1, len(arr)):
            while arr[hi] - arr[lo] > p:
                lo += 1
            count += hi - lo
        print 'Case #%d: %d' % (test, count)

main()
