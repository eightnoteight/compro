from itertools import cycle
from operator import itemgetter

def main():
    n = int(raw_input())
    l = [0, 0, 0, 0, 0, 1, 1]
    pos = [sum(map(itemgetter(0), zip(cycle(l[x:] + l[:x]), xrange(n)))) for x in xrange(7)]
    print min(pos), max(pos)

main()
