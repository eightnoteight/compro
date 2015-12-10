from sys import stdin

def main():
    nextint = map(int, stdin.read().split()).__next__
    for _ in range(nextint()):
        n1, n2, m = nextint(), nextint(), nextint()
        print(n1 + n2 - 2*min((m * (m + 1)) // 2, n1, n2))

main()
