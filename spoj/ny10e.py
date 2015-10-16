from math import factorial


def main():
    for _ in xrange(int(raw_input())):
        d, i = map(int, raw_input().split())
        ans = 1
        for x in xrange(i + 9, i, -1):
            ans *= x
        ans //= factorial(9)
        print d, ans


main()
