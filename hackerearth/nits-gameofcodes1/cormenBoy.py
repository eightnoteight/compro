from sys import stdin

def main():
    nextint = iter(map(int, stdin.read().split())).next
    n, k = nextint(), nextint()
    n2, ans = n // 2, float('-inf')
    for _ in xrange(k):
        arr = [nextint() for _ in xrange(n)]
        lparr = [0]
        for x in xrange(n):
            lparr.append(lparr[-1] + arr[x])
        rparr = [0]
        for x in xrange(n - 1, -1, -1):
            rparr.append(rparr[-1] + arr[x])
        for x in xrange(0, n2 + 1):
            ans = max(lparr[x] + rparr[n2 - x], ans)
    print ans


main()
