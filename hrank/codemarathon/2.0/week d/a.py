from sys import stdin

def main():
    # next = iter(stdin.read().split()).next
    nextint = iter(map(int, stdin.read().split())).next
    mod = 1000000007
    for _ in xrange(nextint()):
        n = nextint()
        print (pow(5, mod - 2, mod) * (pow(6, n + 1, mod) - 6)) % mod

main()
