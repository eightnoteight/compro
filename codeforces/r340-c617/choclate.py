
def bsearch(lo, hi, check):
    while lo < hi:
        mid = lo + ((hi - lo) // 2)
        if check(mid):
            hi = mid
        else:
            lo = mid + 1
    return lo

def main():
    n = int(raw_input())
    arr = map(int, raw_input().split())
    for x in xrange(1, n):
        arr[x] += arr[x - 1]
    if arr[-1] == 0:
        print 0
        return
    try:
        i = arr.index(2)
        dp = [1]*i
        for x in xrange(i, n):
            if arr[x] != arr[x - 1]:
                j = bsearch(0, n, lambda idx: arr[idx] >= arr[x] - 1)
                dp.append((x - j) * dp[j])
            else:
                dp.append(dp[-1])
        print dp[-1]
    except ValueError:
        print 1

main()




