from sys import stdin


def main():
    mod = 1000000007
    nextint = iter(map(int, stdin.read().split())).next
    for _ in xrange(nextint()):
        n, d = nextint(), nextint()
        h = 0
        for i, x in enumerate(str(int(str(d)*n)**2)):
            h += pow(23, i, mod)*int(x)
        print h % mod


main()
