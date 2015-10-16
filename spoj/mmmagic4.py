from itertools import permutations


# ahhhh! the most stupid way to solve a problem
# i haven't learned anything from this problem
# have to find another way

def main():
    Mickey = {}
    Donald = {}


    for p in xrange(1, 28):
        for q in xrange(1, 28):
            for r in xrange(1, 28):
                for s in xrange(1, 28):
                    if len(set((p, q, r, s))) == 4:
                        for perm in permutations([p, q, r], 3):
                            if (tuple(sorted((p, q, r, s))) not in Mickey) and (perm not in Donald):
                                Mickey[tuple(sorted((p, q, r, s)))] = perm
                                Donald[perm] = s
    m, d = map(int, raw_input().split())
    for x in xrange(m):
        y = tuple(sorted(map(int, raw_input().split())))
        print '%d %d %d' % Mickey[y]
    for x in xrange(d):
        y = tuple(map(int, raw_input().split()))
        print Donald[y]

main()
