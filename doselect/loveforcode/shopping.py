from heapq import heappush, heappop

class unionfind:
    def __init__(self, n):
        self._length = n
        self._roots = [x for x in range(n)]
        self._weights = [1]*n

    def __str__(self):
        return str(self._roots)

    def union(self, a, b):
        aroot, broot = self.find(a), self.find(b)
        if aroot == broot:
            return
        if self._weights[aroot] > self._weights[broot]:
            broot, aroot = aroot, broot
        self._roots[aroot] = broot
        self._weights[broot] += self._weights[aroot]
        self._weights[aroot] = 0

    def connected(self, a, b):
        return self.find(a) == self.find(b)

    def find(self, a):
        roots = self._roots
        while roots[a] != a:
            roots[a] = roots[roots[a]]
            a = roots[a]
        return a

def constructMST(graph):
    edgeweight = 0
    uf = unionfind(len(graph))
    nascent = sorted([(d, x, y) for x in range(len(graph)) for y, d in graph[x]])
    while nascent:
        d, x, y = heappop(nascent)
        if uf.connected(x, y):
            continue
        uf.union(x, y)
        edgeweight += d
    return edgeweight, all([uf.connected(0, x) for x in range(len(graph))])

def distance(graph, x, y):
    dist = [float('inf')]*len(graph)
    queue = [(0, x)]
    while queue:
        d, x = heappop(queue)
        if dist[x] > d:
            dist[x] = d
            for c, w in graph[x]:
                heappush(queue, (d + w, c))
    return dist[y]

def main():
    n, m, x, y = map(int, input().split())
    n, x, y = n + 2, x - 1, y - 1
    graph = [[] for _ in range(n)]
    graph_x = [[] for _ in range(n - 1)]
    for _ in range(m):
        a, b, d = map(int, input().split())
        a, b = a - 1, b - 1
        graph[a].append((b, d))
        graph[b].append((a, d))
        if a != x and b != x:
            if a > x:
                a -= 1
            if b > x:
                b -= 1
            graph_x[a].append((b, d))
            graph_x[b].append((a, d))
    mstw, _ = constructMST(graph)
    xmstw, c = constructMST(graph_x)
    mindistmst = mstw
    if c:
        mindistmst = min(xmstw, mstw)
    print(distance(graph, x, y) + mindistmst)

main()
