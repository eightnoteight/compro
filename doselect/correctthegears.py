# i love oneliners
from itertools import cycle
from operator import itemgetter

def dist(arra, arrb):
    return len([None for x, y in zip(arra, arrb) if x != y])

def main():
    assembly = raw_input().strip()
    print min(
        dist(assembly, ''.join(map(itemgetter(1), zip(xrange(len(assembly)), cycle('AC'))))),
        dist(assembly, ''.join(map(itemgetter(1), zip(xrange(len(assembly)), cycle('CA'))))))

main()
