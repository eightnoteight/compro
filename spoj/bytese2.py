# fuck me, Wrong Answer


def main():
    def bytese2(entries):
        times = tuple(item for tup in entries for item in tup)
        mc = float('-inf')
        for x in times:
            c = 0
            for entry in entries:
                if x in xrange(entry[0], entry[1] + 1):
                    c += 1
            mc = max(c, mc)
        return mc
    for _ in xrange(int(raw_input())):
        print bytese2(tuple(tuple(map(int, raw_input().split())) for x in xrange(int(raw_input()))))


main()
