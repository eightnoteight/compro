
def circle_len(arr, i, couples):
    visited = set([i])
    while arr[i] not in visited:
        visited.add(arr[i])
        li = i
        i = arr[i]
    if arr[i] == li:
        couples[i] = max(couples[i], len(visited) + (count[i] > ))
        couples[li] = max(couples[li], len(visited) + )
        return 0
    else:
        k = 1
        i = arr[i]
        p = i
        while arr[i] != p:
            i = arr[i]
            k += 1
        return k



def main():
    for t in xrange(1, 1 + int(raw_input())):
        n = int(raw_input())
        arr = [x - 1 for x in map(int, raw_input().split())]
        couples = {}
        for x in arr:
            if arr[arr[x]] == x:
                couples[x] = 0
        ans = 0
        print arr
        for x in xrange(n):
            ans = max(ans, circle_len(arr, x, couples))
        print couples
        print sum(couples.values())
        print 'Case #%s: %s' % (t, max(ans, sum(couples.values()) // 2))


main()
