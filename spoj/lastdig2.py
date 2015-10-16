table = [
    [0, 0, 0, 0],
    [1, 1, 1, 1],
    [6, 2, 4, 8],
    [1, 3, 9, 7],
    [6, 4, 6, 4],
    [5, 5, 5, 5],
    [6, 6, 6, 6],
    [1, 7, 9, 3],
    [6, 8, 4, 2],
    [1, 9, 1, 9],
]
for _ in xrange(int(raw_input())):
    a, b = raw_input().split()
    if b == '0':
        print 1
        continue
    b = int(b) % 4
    print table[int(a[-1])][b]
