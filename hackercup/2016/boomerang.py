from collections import defaultdict

def main():
    for i in xrange(1, int(raw_input()) + 1):
        points = [map(int, raw_input().split()) for _ in xrange(int(raw_input()))]
        boomerangs = 0
        for cx, cy in points:
            dists = defaultdict(int)
            for dx, dy in points:
                dists[(dx - cx)**2 + (dy - cy)**2] += 1
            boomerangs += sum([(v*(v - 1)) // 2 for v in dists.values()])
        print 'Case #%d: %d' % (i, boomerangs)

main()
