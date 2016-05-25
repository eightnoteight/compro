from sys import stdin


def bsearch(lo, hi, check):
    while lo < hi:
        mid = lo + ((hi - lo) // 2)
        if check(mid):
            hi = mid
        else:
            lo = mid + 1
    return lo

def main():
    nextint = iter(map(int, stdin.read().split())).next
    # next = iter(stdin.read().split()).next
    n = nextint()
    sqrtn = int(n ** 0.5)
    arri = [nextint() for _ in xrange(n)]
    arrs = []
    for x in xrange(n):
        if x % sqrtn == 0:
            arrs.append([arri[x]])
        else:
            arrs[-1].append(arri[x])
    for arr in arrs:
        arr.sort()
    # print arrs
    offsets = [0]*len(arrs)
    out = []
    for _ in xrange(nextint()):
        if nextint():
            l, r, qx, qy = nextint() - 1, nextint(), nextint(), nextint()
            ln = l // sqrtn
            rn = r // sqrtn
            count = 0
            if r - l < 2*sqrtn:
                count += len([None for x in xrange(l, r) if qx <= arri[x] + offsets[x // sqrtn] <= qy])
            else:
                if l % sqrtn != 0:
                    for x in xrange(l, min(n, (ln + 1) * sqrtn)):
                        if qx <= arri[x] + offsets[x // sqrtn] <= qy:
                            count += 1
                    ln += 1
                if r % sqrtn != 0:
                    for x in xrange(rn * sqrtn, r):
                        if qx <= arri[x] + offsets[x // sqrtn] <= qy:
                            count += 1
                for x in xrange(ln, rn):
                    qqy = qy - offsets[x]
                    qqx = qx - offsets[x]
                    lx = len(arrs[x])
                    _xy = bsearch(0, lx, lambda k: arrs[x][k] > qqy) - bsearch(0, lx, lambda k: arrs[x][k] >= qqx)
                    count += _xy

            out.append(count)
        else:
            l, r = nextint() - 1, nextint()
            ln = l // sqrtn
            rn = r // sqrtn
            if r - l < 2*sqrtn:
                for x in xrange(ln * sqrtn, min(n, (ln + 1) * sqrtn)):
                    arri[x] += offsets[ln]
                offsets[ln] = 0
                for x in xrange(rn * sqrtn, min(n, (rn + 1) * sqrtn)):
                    arri[x] += offsets[rn]
                offsets[rn] = 0
                for x in xrange(l, r):
                    arri[x] += 1
                for y in xrange(ln, rn + 1):
                    arrs[y] = sorted(arri[y * sqrtn: (y + 1) * sqrtn])
            else:
                if l % sqrtn != 0:
                    for x in xrange(ln * sqrtn, min(n, (ln + 1) * sqrtn)):
                        arri[x] += offsets[ln]
                    offsets[ln] = 0
                    for x in xrange(l, min(n, (ln + 1) * sqrtn)):
                        arri[x] += 1
                    arrs[ln] = sorted(arri[ln * sqrtn: (ln + 1) * sqrtn])
                    ln += 1
                if r % sqrtn != 0:
                    for x in xrange(rn * sqrtn, min(n, (rn + 1) * sqrtn)):
                        arri[x] += offsets[rn]
                    offsets[rn] = 0
                    for x in xrange(rn * sqrtn, r):
                        arri[x] += 1
                    arrs[rn] = sorted(arri[rn * sqrtn: (rn + 1) * sqrtn])
                for x in xrange(ln, rn):
                    offsets[x] += 1
    print '\n'.join(map(str, out))


main()
