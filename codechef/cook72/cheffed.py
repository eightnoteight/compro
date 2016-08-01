def main():
    n = int(raw_input())
    s = lambda x: sum(map(int, str(x)))
    f = lambda x: x + s(x) + s(s(x))
    print sum([(f(x) == n) for x in xrange(max(0, n - 1000), n)])

main()
