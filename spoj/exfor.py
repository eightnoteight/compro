def main():
    for x in xrange(int(raw_input())):
        l = map(int, raw_input().split())
        a = 0
        for x in xrange(10):
            for y in xrange(x + 1, 10):
                a ^= l[x] or l[y]
                for z in xrange(y + 1, 10):
                    a ^= l[x] or l[y] or l[z]
        print a


main()
