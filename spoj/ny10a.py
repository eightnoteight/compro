counts = [0, 0, 0, 0, 0, 0, 0, 0]
for _ in xrange(int(raw_input())):
    counts = [0, 0, 0, 0, 0, 0, 0, 0]
    n = raw_input()
    seq = raw_input().replace('T', '0').replace('H', '1')
    for x in xrange(38):
        counts[int(seq[x: x + 3], 2)] += 1
    print n,
    for x in counts:
        print x,
    print
