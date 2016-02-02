
def xorsum(n):
    xs = 0
    for x in range(len(bin(n)[2:]) - 1, 0, -1):
        x2 = 1 << x
        if (n & (x2 - 1)) % 2 == 0 and n & x2:
            xs ^= x2
    return xs ^ bool((n + 1) & 2)

def main():
    for _ in range(int(input())):
        l, r = map(int, input().split())
        if (r - l + 1) % 2:
            print(xorsum(l) ^ (xorsum(r // 2) << 1) ^ (xorsum(l // 2) << 1) ^ ((((r // 2) - (l // 2)) % 2) * (r % 2)))
        else:
            print((xorsum(r // 2) << 1) ^ (xorsum((l - 1) // 2) << 1) ^ ((((r // 2) - ((l - 1) // 2)) % 2) * (r % 2)))


main()
