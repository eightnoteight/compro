def main():
    inp1 = map(int, raw_input().split())
    while inp1 != [0, ]:
        inp2 = map(int, raw_input().split())
        seq = {}
        for x in inp1[1:]:
            seq[x] = False
        count = 0
        for x in inp2[1:]:
            try:
                if seq[x]:
                    pass
                seq[x] = True
                count += 1
            except KeyError:
                seq[x] = False
        sum1 = [0] * (count + 1)
        sum2 = [0] * (count + 1)
        c = 0
        for x in inp1[1:]:
            if seq[x] is False:
                sum1[c] += x
            else:
                c += 1
                sum1[c] += x
        c = 0
        for x in inp2[1:]:
            if seq[x] is False:
                sum2[c] += x
            else:
                c += 1
                sum2[c] += x
        megasum = 0
        for x in xrange(count + 1):
            megasum += sum1[x] if sum1[x] > sum2[x] else sum2[x]
        print megasum
        inp1 = map(int, raw_input().split())

main()
