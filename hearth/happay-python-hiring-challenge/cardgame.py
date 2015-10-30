from sys import stdin

def jumps(n, m, x, y, a, b):
    jcnt = min(
        ((n - x - 1 if a >= 0 else x) // abs(a)) if a != 0 else float('inf'),
        ((m - y - 1 if b >= 0 else y) // abs(b)) if b != 0 else float('inf'))
    return x + jcnt*a, y + jcnt*b, jcnt if jcnt != float('inf') else 0

def main():
    nextint = iter(map(int, stdin.read().split())).next
    for _ in xrange(nextint()):
        n, m, k = nextint(), nextint(), nextint()
        x, y = 0, 0
        jumpscnt = 0
        for _ in xrange(k):
            x, y, j = jumps(n, m, x, y, nextint(), nextint())
            jumpscnt += j
        print jumpscnt

main()
