
def main():
    n, d, h = map(int, raw_input().split())
    if h < (d + 1) // 2:
        print -1
        return
    if h == 1 == d and n != 2:
        print -1
        return
    edges = []
    if h == d and n > 2:
        for x in xrange(1, h + 1):
            edges.append((x, x + 1))
        for x in xrange(h + 2, n + 1):
            edges.append((h, x))
    else:
        for x in xrange(1, h + 1):
            edges.append((x, x + 1))
        l = 1
        for x in xrange(h + 2, d + 2):
            edges.append((l, x))
            l = x
        for x in xrange(d + 2, n + 1):
            edges.append((1, x))
    out = []
    for x in edges:
        out.append(' '.join(map(str, x)))
    print '\n'.join(out)

main()
