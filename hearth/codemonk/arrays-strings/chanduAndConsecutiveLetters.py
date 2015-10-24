from operator import itemgetter
from itertools import groupby
for _ in xrange(int(raw_input())):
    print ''.join(map(itemgetter(0), groupby(raw_input())))
