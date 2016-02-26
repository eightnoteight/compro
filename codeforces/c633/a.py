def gcd(a, b):
    while b:
        a, b = b, a % b
    return a


def main():
    x, y, z = map(int, raw_input().split())
    for i in xrange(-100000, 100000):
        if (z - i * x) % y == 0:
            print 'Yes'
            break
    else:
        print 'No'

main()
