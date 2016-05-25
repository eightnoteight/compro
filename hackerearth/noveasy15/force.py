for _ in xrange(int(raw_input())):
    a, b, n, m = map(int, raw_input().split())
    arr = [a, b]
    ia, ib = a, b
    for cx in xrange(2, n):
        a, b = b, (a + b) % m
        if a == ia and b == ib:
            arr.pop()
            break
        arr.append(b)
    modarr = [0]*m
    size = len(arr)
    for x in xrange(n % size):
        modarr[arr[x]] += 1
    for x in xrange(size):
        modarr[arr[x]] += n // size
    print sum(map(lambda x: x*x, modarr))
