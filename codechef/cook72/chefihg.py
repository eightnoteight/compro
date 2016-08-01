def get_path(mat, x, y):
    stack = []

def main():
    n, m = map(int, raw_input().split())
    mat = [raw_input().strip() for _ in xrange(n)]
    answer = []
    for x in xrange(n):
        for y in xrange(m):
            if mat[x][y] == '.':
                answer.append(get_path(mat, x, y))
    print ''.join(answer)

main()
