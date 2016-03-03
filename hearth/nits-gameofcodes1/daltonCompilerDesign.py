from sys import stdin

def main():
    nextint = iter(map(int, stdin.read().split())).next
    for _ in xrange(nextint()):
        n = nextint()
        print n // 2, n - (n // 2)

main()
