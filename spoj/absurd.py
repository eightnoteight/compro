

def main():
    for _ in xrange(int(raw_input())):
        c = int(raw_input())
        x = 0
        while (c % 10) == 0:
            c //= 10
            x += 1
        d = c % 10
        c *= 10**x
        if d != 5:
            if (0.95*c <= c - min(d, abs(5 - d), 10 - d)*(10**x)) or (c + min(d, abs(5 - d), 10 - d)*(10**x) <= 1.05*c):
                print 'absurd'
            else:
                print 'not absurd'
        else:
            if (0.95*c <= c - 5*(10**x)) or (c + 5*(10**x) <= 1.05*c):
                print 'absurd'
            else:
                print 'not absurd'


main()
