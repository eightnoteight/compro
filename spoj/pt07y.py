def dfs(g, v, e):
    # g=graph, v=no of vertices, e=no of edges
    stack = [0]
    mark = [0] * v
    ans = True
    while stack:
        node = stack.pop()
        if not mark[node]:
            stack.extend(g[node])
        mark[node] += 1
        if mark[node] > len(g[node]) + 1:
            ans = False
            break
    return ans and all(mark)


def main():
    n, m = map(int, raw_input().split())
    graph = [[] for x in xrange(n)]
    for x in xrange(m):
        u, v = map(int, raw_input().split())
        graph[u - 1].append(v - 1)
        graph[v - 1].append(u - 1)
    # a tree contains n - 1 edges for n vertices
    if m != n - 1:
        return False
    return dfs(graph, n, m)
if main():
    print 'YES'
else:
    print 'NO'
