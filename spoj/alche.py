from sys import stdin


def main():
    inp = map(int, stdin.read().split())
    print '\n'.join(['Y' if round(1000/37.0, 6) == round(inp[2*x]/float(inp[2*x + 1]), 6) else 'N' for x in xrange((len(inp) - 2) // 2)])

main()
