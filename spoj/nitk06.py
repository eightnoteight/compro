for tests in xrange(int(raw_input())):
    n = int(raw_input())
    a = map(int, raw_input().split())
    last = a[0]
    for x in xrange(1, n):
        last = a[x] - last
    if last == 0:
        print('YES')
    else:
        print('NO')
