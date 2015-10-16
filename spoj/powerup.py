from sys import stdin


def main():
    inp = map(int, stdin.read().split())
    inp.pop()
    inp.pop()
    inp.pop()
    for x in xrange(len(inp) // 3):
        if inp[3 * x + 2] == 0:
            print inp[3 * x] % 1000000007
        elif inp[3 * x + 1] == 0:
            print 1
        elif inp[3 * x] % 1000000007 == 0:
            print 0
        else:
            print(pow(
                inp[3 * x],
                pow(
                    inp[3 * x + 1],
                    inp[3 * x + 2],
                    1000000006),
                1000000007))


main()
