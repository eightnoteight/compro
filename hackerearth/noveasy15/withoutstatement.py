for _ in xrange(int(raw_input())):
    n, m = map(int, raw_input().split())
    arr = [sum([int(x)**2 for x in str(n)])]
    arrset = set(arr)
    for x in xrange(m - 1):
        arr.append(sum([int(x)**2 for x in str(arr[-1])]))
        if arr[-1] in arrset:
            # arr.pop()
            break
        arrset.add(arr[-1])
    else:
        print arr[-1]
        continue
    narr, recur = [], None
    for x in xrange(len(arr) - 1):
        if arr[x] == arr[-1]:
            recur = arr[x:-1]
            break
        else:
            narr.append(arr[x])
    assert recur is not None
    if m <= len(narr):
        print narr[m - 1]
    else:
        m -= len(narr) + 1
        print recur[m % len(recur)]

