from sys import stdin
from collections import defaultdict
from collections import deque

def bfs(construct, tree):
    queue = deque([0])
    visited = set([0])
    while queue:
        node = queue.popleft()
        for c in construct[node]:
            if c not in visited:
                tree[node].append(c)
                visited.add(c)
                queue.append(c)

def bfs1(tree, vals, addx, addy, addi):
    queue = deque([0])
    vals[0] += addx[0]
    while queue:
        p = queue.popleft()
        for c in tree[p]:
            addx[c] += addx[p]
            addy[c] += addy[p] + addi[p]
            vals[c] += addx[c] + addy[c]
            addi[c] += addi[p]
            queue.append(c)


def main():
    nextint = iter(map(int, stdin.read().split())).next
    n = nextint()
    edges = [(nextint() - 1, nextint() - 1)for _ in xrange(n - 1)]
    construct = defaultdict(list)
    for x, y in edges:
        construct[x].append(y)
        construct[y].append(x)
    tree = defaultdict(list)
    bfs(construct, tree)
    vals = defaultdict(int)
    addx = defaultdict(int)
    addy = defaultdict(int)
    addi = defaultdict(int)
    for _ in xrange(nextint()):
        u, x, y = nextint() - 1, nextint(), nextint()
        addx[u] += x
        addi[u] += y
    bfs1(tree, vals, addx, addy, addi)
    print '\n'.join([str(vals[x] % 1000000007) for x in xrange(n)])

main()
