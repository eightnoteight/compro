

def main():
    for _ in xrange(int(raw_input())):
        n = int(raw_input())
        entries = []
        for x in xrange(n):
            y = map(int, raw_input().split())
            entries.append((y[0], 1))
            entries.append((y[1], -1))
        entries.sort(key=lambda x: x[0])
        mc = 0
        c = 0
        for x in xrange(2*n):
            if entries[x][1] == 1:
                c += 1
            else:
                c -= 1
            if c < 0:
                c = 0
            if mc < c:
                mc = c
        print mc

main()
