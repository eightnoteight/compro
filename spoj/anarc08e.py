while True:
    a, b = map(int, raw_input().split())
    if a == -1 and b == -1:
        break
    if a == 1 or b == 1:
        print "%d+%d=%d" % (a, b, a + b)
    else:
        print "%d+%d!=%d" % (a, b, a + b)
