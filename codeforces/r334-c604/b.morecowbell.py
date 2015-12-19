from sys import stdin

def main():
    nextint = map(int, stdin.read().split()).__next__
    n, k = nextint(), nextint()
    s = [nextint() for _ in range(n)]
    print(max([s[x] + s[y] \
            for x, y in zip(range(n - k - 1, -1, -1), range(n - k, n))] + [s[-1]]))

main()
