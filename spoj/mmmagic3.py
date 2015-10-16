def main():
    Mickey = {}
    Donald = {}
    for x in xrange(1, 9):
        for y in xrange(1, 9):
            for z in xrange(1, 9):
                if x != y and y != z and x != z:
                    try:
                        Mickey[tuple(sorted((x, y, z)))]
                    except KeyError:
                        try:
                            Donald[(x, y)]
                            try:
                                Donald[(y, x)]
                            except KeyError:
                                Mickey[tuple(sorted((x, y, z)))] = (y, x)
                                Donald[(y, x)] = z
                        except KeyError:
                            Mickey[tuple(sorted((x, y, z)))] = (x, y)
                            Donald[(x, y)] = z


    m, d = map(int, raw_input().split())
    for x in xrange(m):
        y = tuple(sorted(map(int, raw_input().split())))
        print Mickey[y][0], Mickey[y][1]
    for x in xrange(d):
        y = tuple(map(int, raw_input().split()))
        print Donald[y]


main()
