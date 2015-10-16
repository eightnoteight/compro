from sys import stdin
from itertools import imap

def main():
    cache = {0: 1, 1: 2, 2: 1}
    def circ(n):
        try:
            return cache[n]
        except KeyError:
            pass
        ans = 0
        for x in xrange(2, n + 1, 2):
            try:
                t = cache[x - 2]
            except KeyError:
                cache[x - 2] = circ(x - 2)
                t = cache[x - 2]
            try:
                ans += t * cache[n - x]
            except KeyError:
                cache[n - x] = circ(n - x)
                ans += t * cache[n - x]
        return ans
    for x in imap(int, stdin):
        if x is -1:
            break
        print circ(2*x)


main()
