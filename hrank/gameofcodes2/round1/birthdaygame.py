from sys import stdin


def main():
    nextint = iter(map(int, stdin.read().split())).next
    for _ in xrange(nextint()):
        n = nextint()
        arr = [nextint() for _ in xrange(n)][::-1]
        scores = [[0, 0, 0], [0, 0, 0]]
        for x in xrange(1, n + 1):
            scores[0].append(max(sum(arr[x - y: x]) + scores[1][-y] for y in [1, 2, 3]))
            scores[1].append(min(scores[0][-y] for y in [2, 3, 4]))
        print scores[0][-1]

main()
