from itertools import groupby

def main():
    def iterlength(x):
        c = 0
        for t in x:
            c += 1
        return c
    while True:
        try:
            testcases = int(raw_input())
            break
        except ValueError:
            pass
    _ = 0
    while _ < testcases:
        s = raw_input().strip().split()
        if not s:
            continue
        l = map(len, s)
        m = float('-inf')
        for x in groupby(l):
            m = max(m, iterlength(x[1]))
        print m
        _ += 1


main()
