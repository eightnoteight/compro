from sys import stdin

def main():
    sieve = [0]*1000001
    cache = [0]*1000001
    for x in xrange(2, 1000001):
        if not sieve[x]:
            for y in xrange(x, 1000001, x):
                if not sieve[y]:
                    sieve[y] = 1
                    cache[x] += 1
    nextint = iter(map(int, stdin.read().split())).next
    print '\n'.join([str(cache[nextint()]) for _ in xrange(nextint())])

main()
