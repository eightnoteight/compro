from sys import stdin


def main():
    raw_input = iter(stdin.read().split()).next
    for _ in xrange(int(raw_input())):
        print sum([abs(i + 1 - x) for i, x in enumerate(sorted([int([raw_input(), raw_input()][1]) for _ in xrange(int(raw_input()))]))])

main()
