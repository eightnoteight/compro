from sys import stdin


def main():
    inp = map(int, stdin.read().split())

    for _ in xrange(inp[0]):
        print inp[3*_ + 1]*inp[3*_ + 2] + (inp[3*_ + 1]*(inp[3*_ + 1] - 1) // 2)*inp[3*_ + 3]


main()
