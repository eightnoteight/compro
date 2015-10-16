import array

def main():
    class unionfind:
        def __init__(self, n):
            self._length = n
            self._roots = array.array('I', [x for x in xrange(n)])
            self._weights = array.array('I', [1]*n)
        def union(self, a, b):
            ar = self.find(a)
            br = self.find(b)
            w = self._weights
            r = self._roots
            if w[ar] > w[br]:
                r[br] = ar
                w[ar] += w[br]
                w[br] = 0
            else:
                r[ar] = br
                w[br] += w[ar]
                w[ar] = 0
        def connected(self, a, b):
            return self.find(a) == self.find(b)
        def find(self, a):
            r = self._roots
            while r[a] != a:
                r[a] = r[r[a]]
                a = r[a]
            return a
    class maplist(object):
        def __init__(self, arr, indices):
            self.arr = arr
            self.ind = indices
        def __getitem__(self, i):
            return self.arr[self.ind[i]]
        def __setitem__(self, i, v):
            self.arr[self.ind[i]] = v
        def sort(self):
            for i, x in enumerate(sorted(self)):
                self.arr[self.ind[i]] = x
    for _ in xrange(int(raw_input())):
        s = list(raw_input())
        n = int(raw_input())
        uf = unionfind(len(s))
        m = {}
        for x in xrange(n):
            a, b = map(int, raw_input().split())
            uf.union(a, b)
        for x in xrange(len(s)):
            t = uf.find(x)
            if t != x:
                try:
                    m[t].append(x)
                except:
                    m[t] = [x]
        for x in m:
            m[x].append(x)
            m[x].sort()
            v = maplist(s, m[x])
            v.sort()
        print ''.join(s)


main()
