def ways(n, b):
    cache = {}
    def dismantaling(n, k):
        if (n, k) not in cache:
            if k == 0 or n == 1:
                cache[n, k] = 1
            elif n < b**k:
                cache[n, k] = dismantaling(n, k - 1)
            else:
                cache[n, k] = dismantaling(n - b**k, k) + dismantaling(n, k - 1)
        return cache[n, k]
    k = 0
    while b**k <= n:
        k += 1
    return dismantaling(n, k - 1)

def main():
    for _ in xrange(int(raw_input())):
        n, m = map(int, raw_input().split())
        if m == 1:
            print 1
        else:
            print ways(n, m)

main()
