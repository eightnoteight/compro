from sys import stdin

def main():
    nextint = iter(map(int, stdin.read().split())).next
    for _ in xrange(nextint()):
        n, m = nextint(), nextint()
        darmy = sum([nextint() for _ in xrange(m)])
        for t in xrange(m, n):
            x = nextint()
            if darmy < (x + 1) // 2:
                [nextint() for _ in xrange(t + 1, n)]
                print 'DEFEAT'
                break
            darmy -= (x + 1) // 2
        else:
            print 'VICTORY'
            
main()

