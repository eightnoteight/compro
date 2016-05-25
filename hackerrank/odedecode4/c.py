from sys import stdin
from heapq import heappush, heappop

def dijkstra(src, graph, maindest, maxbus):
    route = [float('inf')]*len(graph)
    pqueue = [(0, src, src, maxbus)]
    while pqueue:
        cost, src, dest, busc = heappop(pqueue)
        if dest == maindest:
            route[dest] = cost
            break
        if route[dest] > cost:
            route[dest] = cost
            for ndest, ndweig in graph[dest]:
                if busc > 0:
                    heappush(pqueue, (route[dest] + ndweig[0], dest, ndest, busc - 1))
                heappush(pqueue, (route[dest] + ndweig[1], dest, ndest, busc))
    # print route
    return route[maindest]

def main():
    nextint = iter(stdin.read().split()).next
    for _ in xrange(int(nextint())):
        n, m, N = int(nextint()), int(nextint()), int(nextint())
        graph = [[] for _ in xrange(n)]
        for _ in xrange(m):
            x, y, z, w = int(nextint()) - 1, int(nextint()) - 1, int(nextint()), int(nextint())
            graph[x].append((y, (w, z)))
            graph[y].append((x, (w, z)))
        src, dest = int(nextint()) - 1, int(nextint()) - 1
        ans = dijkstra(src, graph, dest, N)
        if ans == float('inf'):
            print -1
        else:
            print ans

main()
