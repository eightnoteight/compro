from sys import stdin
from heapq import heappush, heappop

def main():
    nextint = iter(map(int, stdin.read().split())).next
    n, k, q = nextint(), nextint(), nextint()
    friends = [nextint() for _ in xrange(n)]
    top = []
    topset = set()
    out = []
    for _ in xrange(q):
        t, i = nextint(), nextint()
        i -= 1
        if t == 1:
            heappush(top, (friends[i], i))
            topset.add(i)
            if len(top) == k + 1:
                topset.remove(heappop(top)[1])
        else:
            out.append(['NO', 'YES'][i in topset])
    print '\n'.join(out)

main()

