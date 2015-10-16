from array import array
from bisect import bisect_left, bisect_right
def main():
    n = int(raw_input())
    arr = [array('i', [0]*n), array('i', [0]*n), array('i', [0]*n), array('i', [0]*n)]
    for x in xrange(n):
        arr[0][x], arr[1][x], arr[2][x], arr[3][x] = map(int, raw_input().split())
    # arr[0].sort()  # nlogn
    # arr[1].sort()  # nlogn
    # arr[2].sort()  # nlogn
    # arr[3].sort()  # nlogn
    apb = []
    for x in arr[0]:
        for y in arr[1]:
            apb.append(x + y)
    cpd = []
    for x in arr[2]:
        for y in arr[3]:
            cpd.append(x + y)
    ans = 0
    apb.sort()
    cpd.sort()
    for x in apb:
        ans += bisect_right(cpd, -x) - bisect_left(cpd, -x)
    print ans

main()
