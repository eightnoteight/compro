import sys
from collections import deque
from operator import itemgetter

def atstart(_):
    import atexit
    import cStringIO
    buff = cStringIO.StringIO()
    sys.stdout = buff
    @atexit.register
    def _0_():
        sys.__stdout__.write(buff.getvalue())
    return _


def marvel(graph):
    n = len(graph)
    on = n
    for node in graph:
        if not node:
            return "No"
    asgard = set()
    for x in xrange(n):
        if len(graph[x]) == n - 1:
            asgard.add(x)
        elif len(graph[x]) != 3:
            return "No"
    newgraph = [[] for _ in xrange(n)]
    for x in xrange(n):
        if x not in asgard:
            newgraph[x].extend([y for y in graph[x] if y not in asgard])
            if len(newgraph[x]) != 2:
                return "No"
    graph = newgraph
    vanheim = set()
    midgard = set()
    gc = 0
    for x in xrange(n):
        if x not in asgard and x not in vanheim and x not in midgard:
            gc += 1
            if gc > 2:
                return "No"
            if gc == 1:
                Q = deque([x])
                while Q:
                    node = Q.popleft()
                    if node in vanheim:
                        continue
                    vanheim.add(node)
                    Q.extend(graph[node])
            else:
                Q = deque([x])
                while Q:
                    node = Q.popleft()
                    if node in midgard:
                        continue
                    midgard.add(node)
                    Q.extend(graph[node])
    for city in [vanheim, midgard]:
        for x in city:
            if len(graph[x]) != 2:
                return "No"
            for y in graph[x]:
                if y not in city:
                    return "No"
    if len(vanheim) + len(midgard) + len(asgard) != on:
        return "No"
    return "Yes"






@atstart
def main():
    # next = iter(sys.stdin.read().split()).next
    nextint = iter(map(int, sys.stdin.read().split())).next
    for _ in xrange(nextint()):
        n = nextint()
        graph = [set() for _ in xrange(n)]
        edges = []
        for _ in xrange(nextint()):
            a, b = nextint(), nextint()
            if b < a:
                a, b = b, a
            edges.append((a, b))
        if len(edges) != len(set(edges)):
            print 'No'
        else:
            nummap = {x: i for i, x in enumerate(sorted(set(map(itemgetter(0), edges) + map(itemgetter(1), edges))))}
            for a, b in edges:
                graph[nummap[a]].add(nummap[b])
                graph[nummap[b]].add(nummap[a])
            print marvel(graph)

main()
