from sys import stdin

def main():
    nextitem = iter(map(int, stdin.read().split())).next
    for _ in xrange(nextitem()):
        n, k = nextitem(), nextitem() + 1
        arr = [nextitem() for _ in xrange(n)]
        dp = [arr[0] if arr[0] > 0 else 0]
        for x in xrange(1, k):
            dp.append(max(dp[-1], arr[x]))
        for x in xrange(k, n):
            dp.append(max(dp[-1], arr[x] + dp[-k]))
        print dp[-1]

main()
