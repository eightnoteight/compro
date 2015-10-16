def main():
    from sys import stdin
    from math import log
    inp = list(map(int, stdin.read().split()))
    for _ in range(inp[0]):
        try:
            print(int(log(int(inp[3*_ + 3] / inp[3*_ + 1]), inp[3*_ + 2])))
        except ValueError:
            print(0)

main()
