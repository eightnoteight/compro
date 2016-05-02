def main():
    n, m = map(int, raw_input().split())
    arr = set(map(int, raw_input().split()))
    outs = 0
    out = []
    for k in xrange(1, 10**9):
        if k not in arr:
            if outs + k > m:
                break
            out.append(k)
            outs += k
    print len(out)
    print ' '.join(map(str, out))


main()
