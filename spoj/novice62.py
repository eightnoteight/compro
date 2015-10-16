from sys import stdin

def main():
    dearr = [0, 0, 1]
    for n in xrange(2, 1000001):
        dearr.append((n*(dearr[-1] + dearr[-2])) % 1000000007)
    dstream = map(int, stdin.read().split())
    print '\n'.join([str(dearr[dstream[x]]) for x in xrange(1, dstream[0] + 1)])

main()
