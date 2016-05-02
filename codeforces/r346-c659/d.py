from sys import stdin

def main():
    nextint = iter(map(int, stdin.read().split())).next
    n = nextint()
    pts = [(nextint(), nextint()) for _ in xrange(n)]
    last = float('inf')
    dang = 0
    for (x1, y1), (x2, y2) in zip(pts, pts[1:]):
        if x1 == x2:
            cur = (y2 - y1) * float('inf')
        else:
            cur = y2 - y1 / float(x2 - x1)
        if cur > last:
            dang += 1
        last = cur
    print dang

main()

