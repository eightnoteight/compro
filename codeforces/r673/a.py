from sys import stdin

def main():
    nextint = iter(map(int, stdin.read().split())).next
    arr = [0] + [nextint() for _ in xrange(nextint())] + [90]
    s = 0
    for x, y in zip(arr, arr[1:]):
        s = x
        if y - x > 15:
            break
    print min(s + 15, 90)

main()
