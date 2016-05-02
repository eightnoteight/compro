from itertools import groupby, izip
from sys import stdin
from operator import itemgetter

def main():
    nextitem = iter(stdin.read().split()).next
    n, m = int(nextitem()), int(nextitem())
    regs = [[] for _ in xrange(m)]
    for _ in xrange(n):
        sur, r, s = nextitem(), int(nextitem()), int(nextitem())
        regs[r - 1].append((s, sur))
    out = []
    for x in xrange(m):
        regs[x].sort(reverse=True)
        for i, (x, it) in izip((0, 1), groupby(regs[x], key=itemgetter(0))):
            if i == 0:
                items = list(it)
                k = len(items)
                if k > 2:
                    out.append('?')
                    break
                elif k == 2:
                    out.append(items[0][1] + ' ' + items[1][1])
                    break
                else:
                    out.append(items[0][1])
            else:
                items = list(it)
                k = len(items)
                if k > 1:
                    out[-1] = '?'
                    break
                else:
                    out[-1] += ' ' + items[0][1]
    print '\n'.join(out)

main()
