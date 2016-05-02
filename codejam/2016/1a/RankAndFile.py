from collections import defaultdict


def main():
    for t in xrange(1, 1 + int(raw_input())):
        n = int(raw_input())
        counter = defaultdict(int)
        for _ in xrange(2*n - 1):
            for x in map(int, raw_input().split()):
                counter[x] += 1
        arr = []
        for x, y in counter.items():
            if y % 2:
                arr.append(x)
        print 'Case #%s: %s' % (t, ' '.join(map(str, sorted(arr))))

main()
