import array


def knapsack(items, maxweight):
    bestvalues = [[0] * (maxweight + 1)
                  for i in xrange(len(items) + 1)]

    for i, (value, weight) in enumerate(items):
        i += 1
        for capacity in xrange(maxweight + 1):
            if weight > capacity:
                bestvalues[i][capacity] = bestvalues[i - 1][capacity]
            else:
                candidate1 = bestvalues[i - 1][capacity]
                candidate2 = bestvalues[i - 1][capacity - weight] + value

                bestvalues[i][capacity] = max(candidate1, candidate2)

    reconstruction = []
    i = len(items)
    j = maxweight
    while i > 0:
        if bestvalues[i][j] != bestvalues[i - 1][j]:
            reconstruction.append(items[i - 1])
            j -= items[i - 1][1]
        i -= 1
    reconstruction.reverse()
    return bestvalues[len(items)][maxweight], reconstruction


class unionfind:
    def __init__(self, n):
        self._length = n
        self._roots = array.array('L', [x for x in xrange(n)])
        self._weights = array.array('L', [1] * n)

    def __str__(self):
        return str(self._roots)

    def union(self, a, b):
        assert isinstance(a, int) and isinstance(b, int)
        assert a < self._length and b < self._length

        aroot = self.find(a)
        broot = self.find(b)
        if self._weights[aroot] > self._weights[broot]:
            self._roots[broot] = aroot
            self._weights[aroot] += self._weights[broot]
            self._weights[broot] = 0
        else:
            self._roots[aroot] = broot
            self._weights[broot] += self._weights[aroot]
            self._weights[aroot] = 0

    def connected(self, a, b):
        assert isinstance(a, int) and isinstance(b, int)
        assert a < self._length and b < self._length

        return self.find(a) == self.find(b)

    def find(self, a):
        assert isinstance(a, int)

        while self._roots[a] != a:
            self._roots[a] = self._roots[self._roots[a]]
            a = self._roots[a]

        return a

    def _accumulate_weights_at_root(self, weights):
        headroots = {}
        for x in xrange(self._length):
            try:
                headroots[self.find(x)] += weights[x]
            except:
                headroots[self.find(x)] = weights[x]
        items = headroots.items()
        print items
        # New Problem Here
        # [
        #     (i, weight, points),
        #     ...
        # ]

    def max_persons(self, c):
        return self._accumulate_weights_at_root(c)

while True:
    n, C = map(int, raw_input().split())
    weights = map(int, raw_input().split())
    uf = unionfind(n)
    for x in xrange(n):
        likes = map(int, raw_input().split())
        for y in xrange(1, len(likes)):
            uf.union(x, likes[y] - 1)
    print uf.max_persons(C)
