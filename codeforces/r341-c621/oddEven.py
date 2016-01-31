n = int(raw_input())
arr = map(int, raw_input().split())
if sum(arr) % 2:
    print sum(arr) - min([x for x in arr if x % 2])
else:
    print sum(arr)
