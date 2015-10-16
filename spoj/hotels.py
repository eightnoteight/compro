def main():
    n, m = map(int, raw_input().split())
    hotels = map(int, raw_input().split())
    s = 0
    lo = 0
    gt = 0
    for x in xrange(n):
        if s + hotels[x] <= m:
            s += hotels[x]
            if gt < s:
                gt = s
        else:
            while (lo <= x) and (s + hotels[x] > m):
                s -= hotels[lo]
                lo += 1
            s += hotels[x]
            if gt < s:
                gt = s
    print gt


main()
