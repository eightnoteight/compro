from sys import stdin
from operator import itemgetter


def scc_resolve(edges, n):
    def dodfs(graph, x, traversal, visited):
        stack = [x]
        while stack:
            node = stack.pop()
            if not visited[node]:
                visited[node] = True
                stack.append(node)
                for w in graph[node]:
                    if not visited[w]:
                        stack.append(w)
            else:
                if node not in traversal:
                    traversal[node] = len(traversal)

    dgraph = [[] for _ in range(n)]
    tgraph = [[] for _ in range(n)]
    for x, y in edges:
        dgraph[x].append(y)
        tgraph[y].append(x)
    dvisited = [False]*len(dgraph)
    traversal = {}
    for x in range(len(dgraph)):
        if not dvisited[x]:
            dodfs(dgraph, x, traversal, dvisited)
    tvisited = [False]*len(dgraph)
    sccs = {}
    assert len(traversal) == n
    for x, _ in sorted(traversal.items(), key=itemgetter(1), reverse=True):
        if not tvisited[x]:
            tmp = {}
            dodfs(tgraph, x, tmp, tvisited)
            sccs.update(zip(tmp, [min(tmp)]*len(tmp)))
    return sccs

def main():
    nextint = map(int, stdin.read().split()).__next__
    n, m = nextint(), nextint()
    edges = [(nextint(), nextint()) for _ in range(m)]
    sccs = scc_resolve(edges, n)
    print('\n'.join(str(sccs[x]) for x in range(n)))

main()
