
def bsearch(lo, hi, check):
    while lo < hi:
        mid = lo + ((hi - lo) // 2)
        if check(mid):
            hi = mid
        else:
            lo = mid + 1
    return lo

def main():
    n, a, b, t = map(int, raw_input().split())
    s = raw_input().strip()
    t -= (1) if s[0] == 'h' else (b + 1)
    if len(s) == 1:
        print int(t >= 0)
        return
    s = s[1:]
    fc, bc = [(a + 1) if s[0] == 'h' else (a + b + 1)], [(a + 1) if s[-1] == 'h' else (a + b + 1)]
    for x, y in zip(s[1:], s[:len(s) - 1][::-1]):
        fc.append(fc[-1] + ((a + 1) if x == 'h' else (a + b + 1)))
        bc.append(bc[-1] + ((a + 1) if y == 'h' else (a + b + 1)))
    ans = bsearch(0, n - 1, lambda x: bc[x] > t)
    # print t, s, '\n', fc, '\n', bc, '\n', ans
    for i, x in enumerate(fc):
        c = t - x
        if c <= 0:
            break
        k = bsearch(0, n - 1, lambda x: bc[x] > c - (i + x) * a)
        ans = min(max(i + 1 + k, ans), n - 1)
        # print ans, c
    print ans + (t >= 0)

main()
