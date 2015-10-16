
for _ in range(int(input())):
    a, b = map(int, input().split())
    while b:
        a, b = b, a % b
    print(a)
