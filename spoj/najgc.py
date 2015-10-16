def gcd(a, b):
    if b == 0 or a == 0:
        return a or b
    if a < b:
        a, b = b, a
    while b:
        a, b = b, a % b
    return a

for x in xrange(int(raw_input())):
    x1, y1, x2, y2 = map(int, raw_input().split())
    a = (x1*(x2 + 1)) + (y1*(y2 + 1))
    b = (x2 + y2 + 1)*(x1 + y1)
    c = gcd(a, b)
    if a == 0 or b == 0 or c == 0:
        print "Case %d: 0" % (x + 1)
        continue
    else:
        print "Case %d: %d/%d" % (x + 1, a // c, b // c)
