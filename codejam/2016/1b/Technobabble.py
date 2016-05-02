from heapq import heappush, heappop
from collections import defaultdict

def main():
    for t in range(1, 1 + int(input())):
        n = int(input())
        w1, w2 = defaultdict(int), defaultdict(int)
        words = []
        for _ in range(n):
            a, b = input().split()
            words.append((a, b))
            w1[a] += 1
            w2[b] += 1
        mark = set()
        for x, y in w1.items():
            if y == 1:
                mark.add(x)
        nw = []
        for a, b in words:
            if a not in mark:
                nw.append((a, b))
                w1[a] -= 1
                w2[b] -= 1
        words = nw

        mark = set()
        for x, y in w2.items():
            if y == 1:
                mark.add(x)
        nw = []
        for a, b in words:
            if b not in mark:
                nw.append((a, b))
                w1[a] -= 1
                w2[b] -= 1
        words = nw

        for x, v in list(w1.items()):
            if v == 0:
                del w1[x]

        for x, v in list(w2.items()):
            if v == 0:
                del w2[x]


        print('Case #%d: %s' % (t, None))

main()
