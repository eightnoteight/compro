

def main():
    for _ in xrange(int(raw_input())):
        m = int(raw_input())
        l = []
        for i, c in enumerate(raw_input()):
            if c is '1':
                l.append(i)
        print l
        minop = float('inf')
        for x in xrange(m - 1, len(l)):
            minop = min(l[x] - l[x - m + 1], minop)
        print minop + 1 - m


main()
