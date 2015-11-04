from sys import stdin

def main():
    nextint = iter(stdin.read().split()).next
    for _ in xrange(int(nextint())):
        n = int(nextint())
        arra = sorted([int(nextint()) for _ in xrange(n)])
        arrb = sorted([int(nextint()) for _ in xrange(n)])
        print sum([abs(x - y) for x, y in zip(arra, arrb)])

main()
