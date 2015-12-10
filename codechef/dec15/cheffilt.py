from sys import stdin
from itertools import combinations

def xorsum(iterable):
    xs = 0
    for x in iterable:
        xs ^= x
    return xs

def main():
    nextitem = iter(stdin.read().split()).next
    for _ in xrange(int(nextitem())):
        image = int(nextitem().replace('w', '1').replace('b', '0'), 2)
        n = int(nextitem())
        filters = [
            int(nextitem().replace('-', '0').replace('+', '1'), 2) \
                for _ in xrange(n)]
        # print '\n'.join(bin(x)[2:].zfill(10).replace('0', '-').replace('1', '+') for x in filters)
        flags = [1 << x for x in xrange(11)]
        for x in xrange(9, -1, -1):
            filters.sort(reverse=True)
            for y in xrange(n):
                if filters[y] & flags[x] and filters[y] < flags[x + 1]:
                    # print bin(filters[y])[2:].zfill(10).replace('0', '-').replace('1', '+')
                    for z in xrange(n):
                        if z != y and filters[z] & flags[x]:
                            filters[z] ^= filters[y]
                    break
        # print '\n'.join(bin(x)[2:].zfill(10).replace('0', '-').replace('1', '+') for x in filters)
        nums = filter(None, filters)
        if image == 0:
            print pow(2, n - len(nums), 1000000007)
            return
        for x in xrange(1, len(nums) + 1):
            for com in combinations(nums, x):
                if xorsum(com) == image:
                    print pow(2, n - len(nums), 1000000007)
                    break
            else:
                continue
            break
        else:
            print 0

main()
