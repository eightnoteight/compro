
class fibmatwhipmod:
    def __init__(self, mat=None, mod=1000000007):
        self.mod = mod
        self.mat = mat or (1, 1, 1, 0)
        self.cache = {
            0: self.mat,
        }
        self.cache_max = 0

    def fib(self, n):
        from math import log
        try:
            if n < 2:
                return self.mat[3 - n]
            if n == 1 << int(log(n, 2)):
                return self.cache[int(log(n, 2))][1] % self.mod
        except KeyError:
            pass
        cm = self.cache_max
        while int(log(n, 2)) > cm:
            a, b, c, d = self.cache[cm]
            self.cache[cm + 1] = (
                (a * a + b * b) % self.mod,
                (b * (a + d)) % self.mod,
                (b * (a + d)) % self.mod,
                (b * b + d * d) % self.mod
            )
            cm += 1
        self.cache_max = cm
        ans = self.cache[int(log(n, 2))]
        n -= 1 << int(log(n, 2))
        while n > 0:
            tmp = self.cache[int(log(n, 2))]
            ans = (
                (ans[0] * tmp[0] + ans[1] * tmp[2]) % self.mod,
                (ans[0] * tmp[1] + ans[1] * tmp[3]) % self.mod,
                (ans[2] * tmp[0] + ans[3] * tmp[2]) % self.mod,
                (ans[2] * tmp[1] + ans[3] * tmp[3]) % self.mod,
            )
            n -= 1 << int(log(n, 2))
        assert ans[1] == ans[2]
        return ans[1] % self.mod

for _ in xrange(int(raw_input())):
    a, b, n, m = map(int, raw_input().split())
    fibs = fibmatwhipmod(mat=(b, a, a, 0), mod=m)
    print fibs.fib(n + 1)
