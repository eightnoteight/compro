def main():
    s = '1{}1'
    for t in xrange(1, 1 + int(raw_input())):
        n, j = map(int, raw_input().split())
        n -= 2
        print 'Case %d:' % t
        for x in xrange(2**n):
            facs = []
            num_s = s.format(bin(x)[2:].zfill(n))
            for y in xrange(2, 11):
                num = int(num_s, y)
                if not isprime(num):
                    facs.append(getfac(num))
                else:
                    break
            else:
                if j == 0:
                    break
                j -= 1
                print num_s, ' '.join(map(str, facs))


main()
