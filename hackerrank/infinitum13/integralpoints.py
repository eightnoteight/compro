from fractions import gcd

def main():
    for _ in xrange(int(raw_input())):
        x1, y1, x2, y2, x3, y3 = map(int, raw_input().split())
        b = sum([
            gcd(abs(x1 - x2), abs(y1 - y2)),
            gcd(abs(x1 - x3), abs(y3 - y1)),
            gcd(abs(x3 - x2), abs(y3 - x2))])
        print (abs((x1 - x3)*(y2 - y1) - (x1 - x2)*(y3 - y1)) - b) // 2 + 1

main()
