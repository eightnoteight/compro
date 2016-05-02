def _mergedinv(arr, lo, hi, tmp):
    mid = (lo + hi) // 2
    i = lo
    k = lo
    j = mid
    invcnt = 0
    while i < mid and j < hi:
        if arr[i] <= arr[j]:
            tmp[k] = arr[i]
            i += 1
        else:
            tmp[k] = arr[j]
            invcnt += mid - i
            j += 1
        k += 1
    while i < mid:
        tmp[k] = arr[i]
        k += 1
        i += 1
    while j < hi:
        tmp[k] = arr[j]
        k += 1
        j += 1
    arr[lo:hi] = tmp[lo:hi]
    return invcnt

def _inversions(arr, lo, hi, tmp):
    if hi - lo <= 1:
        return 0
    inv = 0
    inv += _inversions(arr, lo, (lo + hi) // 2, tmp)
    inv += _inversions(arr, (lo + hi) // 2, hi, tmp)
    inv += _mergedinv(arr, lo, hi, tmp)
    return inv

def inversions(arr):
    tmp = [0] * len(arr)
    return _inversions(arr, 0, len(arr), tmp)

def main():
    n, k = map(int, raw_input().split())
    cows = range(n)
    for x in xrange(min(k, n // 2)):
        cows[x], cows[-x - 1] = cows[-x - 1], cows[x]
    print inversions(cows)

main()
