a, b, n = map(int, raw_input().split())
arr = [a, b]
for _ in xrange(2, n):
    arr.append(arr[-1] + arr[-2])
print arr[n - 1]
