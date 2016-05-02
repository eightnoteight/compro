from collections import deque

def bfs(start, end):
    Q = deque([start])
    visited = set()
    while Q:
        c = Q.popleft()
        if c in visited:
            continue
        visited.add(c)
        if c == end:
            return 'YES'
        if c[0][0] == 0:
            Q.append(((c[0][1], c[0][0]),
                      (c[1][0], c[1][1])))
            Q.append(((c[1][0], c[0][1]),
                      (c[0][0], c[1][1])))
        elif c[0][1] == 0:
            Q.append(((c[0][1], c[0][0]),
                      (c[1][0], c[1][1])))
            Q.append(((c[0][0], c[1][1]),
                      (c[1][0], c[0][1])))
        elif c[1][0] == 0:
            Q.append(((c[1][0], c[0][1]),
                      (c[0][0], c[1][1])))
            Q.append(((c[0][0], c[0][1]),
                      (c[1][1], c[1][0])))
        elif c[1][1] == 0:
            Q.append(((c[0][0], c[1][1]),
                      (c[1][0], c[0][1])))
            Q.append(((c[0][0], c[0][1]),
                      (c[1][1], c[1][0])))
    return 'NO'
def main():
    res = {'X': 0, 'A': 1, 'B': 2, 'C': 3, 'D': 4}
    start = (tuple(map(lambda x: res[x], raw_input())), tuple(map(lambda x: res[x], raw_input())))
    end = (tuple(map(lambda x: res[x], raw_input())), tuple(map(lambda x: res[x], raw_input())))
    print bfs(start, end)

main()
