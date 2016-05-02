def main():
    n, a, b = map(int, raw_input().split())
    print ((a - 1 + b) % n) + 1

main()
