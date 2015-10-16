from sys import stdin
from sys import stdout


def main():
    n, k = map(int, stdin.readline().split())
    v = set(map(int, stdin.readline().split()))
    stdout.write(str(sum((((x + k) in v) + ((x - k) in v)) for x in v) // 2))


main()
