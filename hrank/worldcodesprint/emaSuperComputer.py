from itertools import combinations, repeat

def expandon(x, y, grid):
    k = min(x + 1, y + 1, len(grid) - x, len(grid[0]) - y)
    pluses = []
    for i in xrange(k):
        if grid[x + i][y] == grid[x - i][y] == 'G' == grid[x][y + i] == grid[x][y - i]:
            pluses.append(
                list(zip(xrange(x - i, x + i + 1), repeat(y))) + \
                list(zip(repeat(x), xrange(y - i, y + i + 1))))
        else:
            break
    return pluses

def isoverlapping(px, py):
    return bool(set(px).intersection(py))


def calcarea(plus):
    return len(plus) - 1

def main():
    n, m = map(int, raw_input().split())
    grid = [raw_input().strip() for x in xrange(n)]
    pluses = []
    for x in xrange(n):
        for y in xrange(m):
            if grid[x][y] == 'G':
                pluses.extend(expandon(x, y, grid))
    maxarea = float('-inf')
    for plusx, plusy in combinations(pluses, 2):
        if not isoverlapping(plusx, plusy):
            maxarea = max(maxarea, calcarea(plusx) * calcarea(plusy))
    print maxarea

main()
