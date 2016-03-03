from itertools import product

def main():
    n = int(raw_input())
    mat = [raw_input().strip() for _ in xrange(n)]
    arr = []
    for x, y in product(xrange(n), xrange(n)):
        if mat[x][y] == 'C':
            arr.append((x, y))
    count = 0
    for x in xrange(len(arr)):
        for y in xrange(len(arr)):
            if x != y and (arr[x][0] == arr[y][0] or arr[x][1] == arr[y][1]):
                count += 1
    print count // 2

main()
