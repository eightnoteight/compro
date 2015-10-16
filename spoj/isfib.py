from sys import stdin
from bisect import bisect_left as bisect


class fibmatwhip:
    def __init__(self):
        self.mat = (1, 1, 1, 0)
        self.cache = {
            0: (1, 1, 1, 0),
        }
        self.cache_max = 0

    def fib(self, n):
        from math import log
        try:
            if n < 2:
                return n
            if n == 1 << int(log(n, 2)):
                return self.cache[int(log(n, 2))][1]
        except KeyError:
            pass
        cm = self.cache_max
        while int(log(n, 2)) > cm:
            a, b, c, d = self.cache[cm]
            self.cache[cm + 1] = (
                a * a + b * b,
                b * (a + d),
                b * (a + d),
                b * b + d * d
            )
            cm += 1
        self.cache_max = cm
        ans = self.cache[int(log(n, 2))]
        n -= 1 << int(log(n, 2))
        while n > 0:
            tmp = self.cache[int(log(n, 2))]
            ans = (
                ans[0] * tmp[0] + ans[1] * tmp[2],
                ans[0] * tmp[1] + ans[1] * tmp[3],
                ans[2] * tmp[0] + ans[3] * tmp[2],
                ans[2] * tmp[1] + ans[3] * tmp[3],
            )
            n -= 1 << int(log(n, 2))
        assert ans[1] == ans[2]
        return ans[1]

inp = map(int, stdin.read().split())
fibgen = fibmatwhip()
fibs = [0, 1]
for x in xrange(62):
    fibs.append(fibs[-1] + fibs[-2])

for x in inp:
    if fibs[bisect(fibs, x)] == x:
        print 'YES'
    else:
        print 'NO'
