for _ in xrange(int(raw_input())):
    string = list(raw_input())
    for x in xrange(len(string) - 1, 0, -1):
        if string[x] > string[x - 1]:
            minmax = x
            for y in xrange(x, len(string)):
                if string[y] > string[x - 1] and string[minmax] > string[y]:
                    minmax = y
            string[x - 1], string[minmax] = string[minmax], string[x - 1]
            string[x:] = sorted(string[x:])
            print ''.join(string)
            break
    else:
        print 'no answer'
