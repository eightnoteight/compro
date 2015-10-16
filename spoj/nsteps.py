from sys import stdin


def main():
    inp = stdin.readlines()
    for _ in xrange(int(inp[0])):
        x, y = map(int, inp[_ + 1].split())
        if x == y:
            print((x // 2) * 4 + (x % 2))
        elif x > 1 and y == x - 2:
            print((y // 2) * 4 + (y % 2) + 2)
        else:
            print('No Number')

main()
