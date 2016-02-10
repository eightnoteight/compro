from sys import stdin

def main():
    nextint = map(int, stdin.read().split()).__next__
    n, m = nextint(), nextint()
    matrix = [[nextint() for _ in range(m)] for _ in range(n)]
    if n == 1:
        print(' '.join(map(str, matrix[0])))
        raise SystemExit
    positions = [(x, -1) for x in range(1, n + 1)]
    increm = [(-1, 1), (1, 1)]
    for cx, cy in positions:
        ix, iy = -1, 1
        arr = []
        while True:
            cx, cy = cx + ix, cy + iy
            if cy == m:
                break
            if not 0 <= cx < n:
                cx, cy = cx - ix, cy - iy
                ix, iy = increm[(ix, iy) == (-1, 1)]
                cx, cy = cx + ix, cy + iy
            # print (cx, cy)
            arr.append(matrix[cx][cy])
        print(' '.join(map(str, arr)))

main()

