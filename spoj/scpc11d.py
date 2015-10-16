from sys import stdin


def main():
    inp = map(int, stdin.read().split())
    for x in xrange((len(inp) - 3) // 3):
        if any([
            inp[3*x]**2 == inp[3*x + 1]**2 + inp[3*x + 2]**2,
            inp[3*x + 1]**2 == inp[3*x]**2 + inp[3*x + 2]**2,
            inp[3*x + 2]**2 == inp[3*x + 1]**2 + inp[3*x]**2,

        ]):
            print 'right'
        else:
            print 'wrong'

main()
