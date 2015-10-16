t = 0
while True:
    t += 1
    n = int(raw_input())
    if n == -1:
        break
    c = map(int, raw_input().split())
    k = int(raw_input())
    xl = map(int, raw_input().split())
    print 'Case {}:'.format(t)
    for x in xl:
        # print the evaluated polynomial
        ans = c[0]
        for p in xrange(1, n + 1):
            ans = ans*x + c[p]
        print ans
