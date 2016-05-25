from sys import stdin
from collections import defaultdict

def topological_sort(dag):
    n = len(dag)
    indegcount = [0]*n
    for x in range(n):
        for c, v in dag[x].items():
            indegcount[c] += v
    order = []
    stack = [x for x in range(n) if indegcount == 0]
    while stack:
        node = stack.pop()
        order.append(node)
        for c, v in dag.items():
            indegcount[c] -= v
            if indegcount[c] == 0:
                stack.append(c)
    return order

def main():
    nextint = map(int, stdin.read().split()).__next__
    n, m = nextint(), nextint()
    graph = [defaultdict(int) for _ in range(n)]
    for _ in range(m):
        graph[nextint() - 1][nextint() - 1] += 1
    print(' '.join(map(str, topological_sort(graph))))

main()
