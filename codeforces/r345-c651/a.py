def main():
    a, b = map(int, raw_input().split())
    ans = 0
    while a > 0 and b > 0:
        if a < b and b > 1:
            a += 1
            b -= 2
        elif a > 1:
            a -= 2
            b += 1
        else:
            break
        ans += 1
        # print a, b
    print ans

main()


# 1:22 336
