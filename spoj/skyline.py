from sys import stdin

def main():
    skyline = [0]*1001
    skyline[0] = 1
    for x in xrange(1, 1001):
        skyline[x] = (
            2*sum([skyline[y] * skyline[x - y - 1] for y in xrange(x // 2)]) + \
            (x % 2)*skyline[x // 2]**2) % 1000000
    print '\n'.join(map(str, map(skyline.__getitem__, map(int, stdin.read().split()[:-1]))))

main()
