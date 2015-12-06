from sys import stdin

def main():
    nextint = iter(map(int, stdin.read().split())).next
    arr = []
    for _ in xrange(nextint()):
        x, y, d = nextint(), nextint(), nextint()
        arr.append((x, x + d))
    blocked, end = 0, 0
    for x, y in sorted(arr):
        if x > end:
            blocked += y - x + 1
            end = y
        elif y > end:
            blocked += y - end
            end = y
    print blocked

main()

