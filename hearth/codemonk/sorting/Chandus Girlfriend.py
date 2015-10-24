for _ in xrange(int(raw_input())):
    raw_input()
    print ' '.join(map(str,
        sorted(map(int, raw_input().split()), reverse=True)))
