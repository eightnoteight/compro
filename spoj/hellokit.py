from sys import stdin


def main():
    inp = stdin.read().split()
    for _ in xrange(len(inp) // 2):
        s = inp[2*_]*2
        m = len(s) // 2
        n = int(inp[2*_ + 1])
        for x in xrange(m):
            print s[x: x + m]*n

main()
