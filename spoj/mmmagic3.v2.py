from itertools import permutations

def main():
    Mickey = {}
    Donald = {}
    m, d = map(int, raw_input().split())
    n = 3
    for x in xrange(m):
        q = tuple(sorted(map(int, raw_input().split())))
        try:
            print "%d %d" % Mickey[q]
        except KeyError:
            for perm in permutations(q, n - 1):
                try:
                    Donald[perm]
                except KeyError:
                    Mickey[q] = perm
                    for x in q:
                        if x not in perm:
                            Donald[perm] = x
                            break
            print "%d %d" % Mickey[q]

    for x in xrange(d):
        q = tuple(map(int, raw_input().split()))
        try:
            print Donald[q]
        except KeyError:
            for y in xrange(1, n + 1):
                if y not in q:
                    Donald[q] = y
                    print y
                    break

main()
