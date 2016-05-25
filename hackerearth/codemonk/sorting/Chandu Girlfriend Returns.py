def merge(arri, arrj):
    arr = []
    for _ in xrange(len(arri) + len(arrj)):
        if (not arri) or (arrj and arri[-1] > arrj[-1]):
            arr.append(arrj.pop())
        else:
            arr.append(arri.pop())
    return reversed(arr)
for _ in xrange(int(raw_input())):
    n, m = map(int, raw_input().split())
    narr = map(int, raw_input().split())
    marr = map(int, raw_input().split())
    print ' '.join(map(str, merge(narr, marr)))
