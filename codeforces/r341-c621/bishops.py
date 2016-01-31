from collections import defaultdict

def main():
    n = int(raw_input())
    pslope = defaultdict(int)
    nslope = defaultdict(int)
    for x in xrange(n):
        x, y = map(int, raw_input().split())
        pslope[x - y] += 1
        nslope[x + y] += 1
    pairs = 0
    for _, v in pslope.items():
        pairs += v * (v - 1) / 2
    for _, v in nslope.items():
        pairs += v * (v - 1) / 2
    print pairs

main()
