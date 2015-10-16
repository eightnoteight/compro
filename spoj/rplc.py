from sys import stdin

def main():
    inp = map(int, stdin.read().split())
    i = 1
    for x in xrange(inp[0]):
        c = 0
        ans = 0
        for y in xrange(inp[i]):
            c += inp[i + y + 1]
            ans = min(ans, c)
        i += inp[i] + 1

        print "Scenario #%d: %d" % (x + 1, 1 - ans)

main()
