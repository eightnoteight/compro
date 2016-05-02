from collections import deque
from itertools import combinations

def dijkstra(src, graph, maindest):
    Q = deque([src, None])
    visited = set()
    k = 0
    while len(Q) > 1:
        n = Q.popleft()
        if n is None:
            Q.append(n)
            k += 1
            continue
        if n == maindest:
            return k
        visited.add(n)
        for x in graph[n]:
            if x not in visited:
                Q.append(x)
    return float('inf')

def bfs(graph, s):
    Q = deque([s, None])
    visited = set()
    k = 0
    while len(Q) > 1:
        n = Q.popleft()
        if n is None:
            Q.append(n)
            k += 1
            continue
        visited.add(n)
        for x in graph[n]:
            if x not in visited:
                Q.append(x)
    return k

def diameter(graph):
    return max([dijkstra(x, graph, y) for x, y in combinations(xrange(len(graph)), 2)])


def main():
    edges = []
    try:
        while True:
            edges.append(map(int, raw_input().split()))
    except EOFError:
        pass
    graph = [[] for _ in xrange(len(edges) + 1)]
    for x, y in edges:
        x -= 1
        y -= 1
        graph[x].append(y)
        graph[y].append(x)
    print len(graph), diameter(graph), bfs(graph, 0)

main()
