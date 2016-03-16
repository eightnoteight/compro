from sys import stdin
from collections import defaultdict
from heapq import heappop, heappush


def main():
    # nextint = iter(map(int, stdin.read().split())).next
    next = iter(stdin.read().split()).next
    for _ in xrange(int(next())):
        s = next()
        k = int(next())
        counter = defaultdict(int)
        for ch in s:
            counter[ch] += 1
        heap = sorted([-x for x in counter.values()])
        # print heap, k
        while heap:
            if k <= 0:
                break
            node = heappop(heap)
            if node == 0:
                break
            heappush(heap, node + 1)
            # print heap
            k -= 1
        # print [x**2 for x in heap]
        print sum([x**2 for x in heap]) % 1000000007


main()
