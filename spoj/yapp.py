from sys import stdin

def main():
    dstream = map(int, stdin.read().split())
    print '\n'.join(str(pow(2, dstream[x] - 1, 1000000007)) for x in xrange(1, dstream[0] + 1))

main()
