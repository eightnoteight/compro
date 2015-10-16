from sys import stdin
from collections import deque


def main():
    def deepestNode(s, c, r, i, j):
        queue = deque([None])
        length = 0
        queue.append((i, j))
        visited = set()
        visited.add((i, j))
        while True:
            node = queue.popleft()
            if node is None:
                length += 1
                queue.append(None)
                continue
            if node[1] < (c - 1) and s[node[0]][node[1] + 1] == '.' and ((node[0], node[1] + 1) not in visited):
                queue.append((node[0], node[1] + 1))
                visited.add((node[0], node[1] + 1))
            if node[1] > 0 and s[node[0]][node[1] - 1] == '.' and ((node[0], node[1] - 1) not in visited):
                queue.append((node[0], node[1] - 1))
                visited.add((node[0], node[1] - 1))
            if node[0] < (r - 1) and s[node[0] + 1][node[1]] == '.' and ((node[0] + 1, node[1]) not in visited):
                queue.append((node[0] + 1, node[1]))
                visited.add((node[0] + 1, node[1]))
            if node[0] > 0 and s[node[0] - 1][node[1]] == '.' and ((node[0] - 1, node[1]) not in visited):
                queue.append((node[0] - 1, node[1]))
                visited.add((node[0] - 1, node[1]))
            if len(queue) == 1:
                break
        return (node, length - 1)
    def longestPathLength(s, c, r):
        breakpoint = False
        for i in xrange(r):
            for j in xrange(c):
                if s[i][j] == '.':
                    node, length = deepestNode(s, c, r, i, j)
                    breakpoint = True
                    break
            if breakpoint:
                break
        return deepestNode(s, c, r, node[0], node[1])[1]
    inp = stdin.readlines()
    inpi = 1
    for _ in xrange(int(inp[0])):
        c, r = map(int, inp[inpi].split())
        inpi += 1
        s = []
        for x in xrange(r):
            s.append(inp[inpi + x].strip())
        inpi += r
        print 'Maximum rope length is %d.' % longestPathLength(s, c, r)

main()
