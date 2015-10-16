from heapq import heappush, heappop
from sys import stdin

def main():
    dstream = iter(map(int, stdin.read().split()))
    n, m = next(dstream), next(dstream)
    marked = [float('inf')]*n
    graph = [[] for _ in xrange(n)]
    for i in xrange(n):
        if next(dstream):
            marked[i] = 0
    for _ in xrange(m):
        u, v, c = next(dstream), next(dstream), next(dstream)
        graph[u - 1].append((v - 1, c))
        graph[v - 1].append((u - 1, c))
    pqueue = []
    for x in xrange(n):
        if marked[x] == 0:
            for edge in graph[x]:
                heappush(pqueue, (edge[1], edge))
    mincost = 0
    while pqueue:
        top = heappop(pqueue)
        if marked[top[1][0]] <= top[0]:
            continue
        mincost += top[1][1]
        marked[top[1][0]] = top[0]
        for edge in graph[top[1][0]]:
            if marked[edge[0]] > edge[1] + top[0]:
                heappush(pqueue, (edge[1] + top[0], edge))
    for x in xrange(n):
        if marked[x] == float('inf'):
            print "impossible"
            break
    else:
        print mincost

main()
