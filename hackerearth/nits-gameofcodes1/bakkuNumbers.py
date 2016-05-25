from sys import stdin

def main():
    nextint = iter(map(int, stdin.read().split())).next
    p1, p2 = nextint(), nextint()
    for _ in xrange(nextint()):
        l, r = nextint(), nextint()
        p1facs = len(xrange(p1, r + 1, p1)) - len(xrange(p1, l, p1))
        p2facs = len(xrange(p2, r + 1, p2)) - len(xrange(p2, l, p2))
        p1p2facs = len(xrange(p1*p2, r + 1, p1*p2)) - len(xrange(p1*p2, l, p1*p2))
        print "{:.6f}".format(round((p1facs + p2facs - p1p2facs) / float(r - l + 1), 6))

main()
