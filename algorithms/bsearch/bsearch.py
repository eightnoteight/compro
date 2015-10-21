def bsearch(lo, hi, check):
    while lo < hi:
        mid = lo + (hi - lo) // 2
        if check(mid):
            hi = mid
        else:
            lo = mid + 1
    return lo

if __name__ == '__main__':
    arr = list(xrange(10))
    print bsearch(0, 10, lambda x: arr[x] >= 0)
