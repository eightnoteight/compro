from sys import stdin

def main():
    nextint = iter(map(int, stdin.read().split())).next
    n, m = nextint(), nextint()
    endpos = [(x, y) for y in xrange(1, m + 1) for x in (1, n)]
    endpos.extend([(x, y) for x in xrange(1, n + 1) for y in (1, m)])
    for _ in xrange(nextint()):
        mx, my, ax, ay, bx, by = (nextint() for _ in xrange(6))
        for px, py in endpos:
            if all([
                    abs(px - mx) + abs(py - my) < abs(px - ax) + abs(py - ay),
                    abs(px - mx) + abs(py - my) < abs(px - bx) + abs(py - by)]):
                print 'YES'
                break
        else:
            print 'NO'

main()
