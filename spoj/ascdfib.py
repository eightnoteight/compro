from sys import stdin

def main():
    nextint = iter(map(int, stdin.read().split())).next
    positions = [[] for _ in xrange(100000)]
    for x in xrange(2):
        positions[x].append(x)
    a, b = 0, 1
    for x in xrange(2, 150000):
        a, b = b, ((a + b) % 100000)
        positions[b].append(x)
    fibs = [x for x in xrange(100000) if positions[x]]
    for testcase in xrange(1, nextint() + 1):
        a, b = nextint(), nextint()
        a, b = a - 1, a + b
        am, bm = a % 150000, b % 150000
        ascdfibs = []
        for fib in fibs:
            if len(ascdfibs) >= 100:
                break
            for pos in positions[fib]:
                k = (
                    (b - bm + (bm > pos)*150000) - \
                    (a - am + (am > pos)*150000)) // 150000
                ascdfibs.extend([fib]*(k if k > 0 else 0))
        print 'Case {}: {}'.format(
            testcase, ' '.join(map(str, ascdfibs[:100])))

main()
