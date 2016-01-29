from sys import stdin

mod = 1000000007

def debugger(func):
    def wrapper(*args, **kwargs):
        info = {
            'args': args,
            'kwargs': kwargs,
            'return': func(*args, **kwargs)
        }
        print info
        return info['return']
    return wrapper

def myfactorize(k):
    facs = [0]*4
    for i, f in enumerate((2, 3, 5, 7)):
        while k % f == 0:
            k /= f
            facs[i] += 1
    return tuple(facs)*(k <= 1)

cache = {}

def decrem(facs, x):
    xfacs = list(facs)
    for i, f in enumerate((2, 3, 5, 7)):
        while x % f == 0:
            x /= f
            xfacs[i] -= 1
    return tuple(xfacs)

cache9 = {}

def gen9(n, facs):
    if any([x < 0 for x in facs]) or n == 0:
        return 0
    if n == 1:
        return int((2**facs[0]) * (3**facs[1]) * (6**facs[2]) * (7**facs[3]) <= 9)
    if (n, facs) not in cache9:
        cache9[n, facs] = sum([gen9(n - 1, decrem(facs, x)) for x in xrange(1, 10)]) % mod
    return cache9[n, facs]


# @debugger
def prodcount(n, facs):
    # print n
    if n[0] == '0' or any([x < 0 for x in facs]):
        return 0
    if facs[0] == facs[1] == facs[2] == facs[3] == 0:
        return ('0' not in n) or any([x > '1' for x in n[:n.index('0')]])
    if len(n) == 1:
        return int((2**facs[0]) * (3**facs[1]) * (5**facs[2]) * (7**facs[3]) <= int(n))
    if (n, facs) not in cache:
        cnt = 0
        for x in xrange(1, int(n[0])):
            cnt += gen9(len(n) - 1, decrem(facs, x))
        cnt += prodcount(n[1:], decrem(facs, int(n[0])))
        cache[n, facs] = cnt % mod
    return cache[n, facs]


def main():
    nextitem = iter(stdin.read().split()).next
    for test in xrange(1, int(nextitem()) + 1):
        a, b, k = nextitem(), nextitem(), int(nextitem())
        facs = myfactorize(k)
        cnt = 0
        if facs:
            for x in xrange(len(b)):
                cnt += gen9(x, facs)
            cnt += prodcount(b, facs)
            for x in xrange(len(a)):
                cnt -= gen9(x, facs)
            cnt -= prodcount(a, facs)
            cnt += (reduce(int.__mul__, map(int, a)) == k)
        print 'Case {}: {}'.format(test, cnt % mod)

main()
