from sys import stdin
from collections import defaultdict
def main():
    dstream = iter(stdin.read().split())
    for _ in xrange(int(next(dstream))):
        string = next(dstream)
        counter = defaultdict(int)
        for ch in string:
            counter[ch] += 1
        if all([counter[x] >= 2 for x in 'LTIM']):
            if counter['E'] >= 2:
                print 'YES'
            elif len(string) == 9 and counter['E'] == 1:
                print 'YES'
            else:
                print 'NO'
        else:
            print 'NO'

main()
