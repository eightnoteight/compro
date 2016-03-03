from sys import stdin

def main():
    nextint = iter(map(int, stdin.read().split())).next
    for _ in xrange(nextint()):
        n, k = nextint(), nextint()
        arr = [0] + [nextint() for _ in xrange(n)]
        cs, y = 0, 0
        counter = [0]*n
        for x in xrange(1, len(arr)):
            cs += arr[x]
            while cs > k:
                y += 1
                cs -= arr[y]
            if x - y > 0:
                counter[x - y - 1] += 1
        for x in xrange(n - 2, -1, -1):
            counter[x] += counter[x + 1]
        print ' '.join(map(str, counter))

main()
