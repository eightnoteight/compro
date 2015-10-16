from itertools import groupby


def main():
    def iterlength(x):
        c = 0
        for t in x:
            c += 1
        return c
    for _ in range(int(input())):
        print(max(iterlength(x[1]) for x in groupby(input().split(), len)))


main()
