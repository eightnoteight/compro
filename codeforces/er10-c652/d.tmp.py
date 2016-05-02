from sys import stdin

def main():
    nextint = iter(map(int, stdin.read().split())).next
    n = nextint()
    vis = [' ']*20
    for _ in xrange(n):
        a, b = nextint(), nextint()
        vis[a: b + 1] = '*'*(b - a + 1)
        print ''.join(vis)
        vis = [' ']*20

main()



