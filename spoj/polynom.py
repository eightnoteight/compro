

def main():
    for _ in xrange(int(raw_input())):
        l = map(int, raw_input().split())
        if l[0] <= 4:
            print 'YES'
            continue
        l.pop(0)
        for x in xrange(1, len(l)):
            l[x - 1] = l[x] - l[x - 1]
        l.pop()
        for x in xrange(1, len(l)):
            l[x - 1] = l[x] - l[x - 1]
        l.pop()
        for x in xrange(1, len(l)):
            l[x - 1] = l[x] - l[x - 1]
        l.pop()
        t = l[0]
        for x in l:
            if x != t:
                print 'NO'
                break
        else:
            print 'YES'

main()
