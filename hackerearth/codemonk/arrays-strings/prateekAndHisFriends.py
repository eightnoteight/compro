for _ in xrange(int(raw_input())):
    n, x = map(int, raw_input().split())
    occ = {0: 0}
    arr = [0]
    for _ in xrange(n):
        arr.append(arr[-1] + int(raw_input()))
        occ[arr[-1]] = 0
    for c in arr:
        if c + x in occ:
            print 'YES'
            break
    else:
        print 'NO'
