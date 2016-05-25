def main():
    s = raw_input()
    k = len(s)
    karr = [10,
            100, 101,
            1000, 1001, 1002,
            10000, 10001, 10002, 10003,
            100000, 100001, 100002, 100003, 100004,
            1000000, 1000001, 1000002, 1000003, 1000004, 1000005,]
    digs = {x: 0 for x in '0123456789'}
    if k in karr:
        k -= len(str(k)) - 1
    for x in s:
        digs[x] += 1
    for x in str(len(str(k))):
        digs[x] -= 1
    sub = raw_input()
    for x in sub:
        digs[x] -= 1
    arr = []
    for x in '0123456789':
        arr.extend([x]*digs[x])
    arr.sort()
    if arr[0] == '0':
        for x in xrange(len(arr)):
            if arr[x] != '0':
                arr[x], arr[0] = arr[0], arr[x]
                break


