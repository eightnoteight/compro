from random import randrange
from operator import itemgetter

def crossinvfreq(arr, freq, lo, mid, hi):
    i, j, tarr = lo, mid, []
    x = 0
    while i < mid and j < hi:
        if arr[i][0] > arr[j][0]:
            tarr.append(arr[j])
            x += 1
            j += 1
        else:
            tarr.append(arr[i])
            freq[arr[i][1]] += x
            i += 1
    while i < mid:
        tarr.append(arr[i])
        freq[arr[i][1]] += x
        i += 1
    while j < hi:
        tarr.append(arr[j])
        j += 1
    arr[lo: hi] = tarr



def invfreq(arr, freq, lo, hi):
    if hi - lo <= 1:
        return
    mid = lo + ((hi - lo) // 2)
    invfreq(arr, freq, lo, mid)
    invfreq(arr, freq, mid, hi)
    crossinvfreq(arr, freq, lo, mid, hi)

def test():
    arr = list(enumerate([randrange(10**9) for _ in xrange(randrange(10**2, 10**5))]))
    tarr = map(itemgetter(0), arr)
    invfreq(arr, [0]*len(arr), 0, len(arr))
    print "{}".format('passed' if sorted(tarr) == map(itemgetter(0), arr) else 'failed')

def main():
    for _ in xrange(int(raw_input())):
        arr = [(int(raw_input()), i) for i in xrange(int(raw_input()))]
        freq = [0]*len(arr)
        invfreq(arr, freq, 0, len(arr))
        # print arr
        print ' '.join(map(str, freq))

# test()
main()

