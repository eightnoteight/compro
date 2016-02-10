from functools import partial

def dist((xa, ya), (xb, yb)):
    return (xb - xa)**2 + (yb - ya)**2

def main():
    n, x1, y1, x2, y2 = map(int, raw_input().split())
    r1dist = partial(dist, (x1, y1))
    r2dist = partial(dist, (x2, y2))
    points = sorted([map(int, raw_input().split()) for _ in xrange(n)], key=r1dist)
    r1, r2 = 0, max(map(r2dist, points))
    ms = float('inf')
    for x in xrange(n):
        r1 = max(map(r1dist, points[:x]) + [0])
        r2 = max(map(r2dist, points[x:]) + [0])
        ms = min(r1 + r2, ms)
    print ms

main()
