


def main():
    for x in xrange(int(raw_input())):
        n, s = raw_input().split()
        if s == 'kg':
            print "%d %.4f lb" % (x + 1, float(n)*2.2046)
        elif s == 'lb':
            print "%d %.4f kg" % (x + 1, float(n)*0.4536)
        elif s == 'l':
            print "%d %.4f g" % (x + 1, float(n)*0.2642)
        else:
            print "%d %.4f l" % (x + 1, float(n)*3.7854)


main()
