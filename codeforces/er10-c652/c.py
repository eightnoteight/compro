from sys import stdin

def main():
    nextint = iter(map(int, stdin.read().split())).next
    n, m = nextint(), nextint()
    permap = {(nextint() - 1): i for i in xrange(n)}
    ends = [n + 1]*n
    for x in xrange(m):
        a, b = sorted([permap[nextint() - 1], permap[nextint() - 1]])
        # print a, b
        ends[a] = min(b + 1, ends[a])
    for x in xrange(n - 2, -1, -1):
        ends[x] = min(ends[x], ends[x + 1])
    print sum([ends[x] - x - 1 for x in xrange(n)])

main()
