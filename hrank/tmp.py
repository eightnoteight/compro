from sys import stdin

def maxsubseq(arra, arrb):
    table = [[[0, [0]*26] for _ in xrange(len(arra) + 1)] for _ in xrange(len(arra) + 1)]
    for x in xrange(1, len(arra) + 1):
        for y in xrange(1, len(arrb) + 1):
            if arra[x - 1] == arrb[y - 1]:
                table[x][y][0] = table[x - 1][y - 1][0] + 1
                table[x][y][1] = table[x - 1][y - 1][1][:]
                if len(arra) // 2 == table[x - 1][y - 1][0]:
                    table[x][y][1][arra[x - 1] - 1] = 1
            else:
                if table[x - 1][y][0] > table[x][y - 1][0]:
                    table[x][y][0] = table[x - 1][y][0]
                    table[x][y][1] = table[x - 1][y][1][:]
                elif table[x][y - 1][0] > table[x - 1][y][0]:
                    table[x][y][0] = table[x][y - 1][0]
                    table[x][y][1] = table[x][y - 1][1][:]
                else:
                    table[x][y][0] = table[x][y - 1][0]
                    table[x][y][1] = [i | j for i, j in zip(table[x][y - 1][1], table[x - 1][y][1])]
    fsols = [0]*26
    for x in xrange(1, len(arra) + 1):
        for y in xrange(1, len(arrb) + 1):
            if table[x][y][0] == table[-1][-1][0]:
                for z in xrange(26):
                    fsols[z] |= table[x][y][1][z]
    return table[-1][-1][0], fsols

def main():
    nextitem = iter(stdin.read().split()).next
    for _ in xrange(int(nextitem())):
        a, b = [ord(ch) - ord('a') for ch in nextitem()], [ord(ch) - ord('a') for ch in nextitem()]
        apal, achars = maxsubseq(a, a[::-1])
        bpal, bchars = maxsubseq(b, b[::-1])
        if (apal % 2) and (bpal % 2):
            for x, y in zip(achars, bchars):
                if x and y:
                    print apal + bpal
                    break
            else:
                print apal + bpal - 1
        else:
            print apal + bpal

main()
