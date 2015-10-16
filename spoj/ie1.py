


def main():
    def totalways(arr, n, lo):
        if n < 0:
            return 0
        if n == 0:
            return 1
        if len(arr) <= lo:
            return 0
        s = 0
        for x in xrange(arr[lo] + 1):
            s += totalways(arr, n - x, lo + 1)
        return s

    k = 1
    n, a, b = map(int, raw_input().split())
    arr = []
    for x in xrange(n):
        m = int(raw_input())
        if (a <= m) and (b <= m):
            arr.append(b - a + 1)
        elif a <= m:
            arr.append(m - a + 1)
        else:
            k *= 1
    if len(arr):
        print totalways(arr, b - a + 1, 0)
    else:
        print 0


main()
