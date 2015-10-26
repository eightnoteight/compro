for _ in xrange(int(raw_input())):
    n = int(raw_input())
    arr = map(int, raw_input().split())
    k = int(raw_input())
    arr = [int(x == k) for x in arr]
    for x in xrange(n - 2, -1, -1):
        arr[x] += arr[x + 1]
    q = int(raw_input())
    mi = n
    for _ in xrange(q):
        i = int(raw_input())
        print arr[i], n - i, mi - i + 1 if i <= mi else 1
        mi = min(i, mi)

