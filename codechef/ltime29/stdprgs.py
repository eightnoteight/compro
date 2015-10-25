from sys import stdin

def main():
    nextint = iter(map(int, stdin.read().split())).next
    n = nextint()
    arr = [nextint() for _ in xrange(n)]
    if all([0 <= x <= 100 for x in arr]):
        counter = [[0]*101]
        for x in xrange(n):
            counter.append(counter[-1][:])
            counter[-1][arr[x]] += 1
        for _ in xrange(nextint()):
            l, r = nextint() - 1, nextint()
            temp = [x for x in xrange(101) if counter[r][x] > counter[l][x]]
            print sum([(temp[x] - temp[x - 1])**2 for x in xrange(1, len(temp))])
    else:
        for _ in xrange(nextint()):
            l, r = nextint(), nextint()
            temp = sorted(arr[l - 1: r])
            print sum([(temp[x] - temp[x - 1])**2 for x in xrange(1, len(temp))])
main()        
