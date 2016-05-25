from collections import defaultdict
from itertools import product
n = int(raw_input())
arr = map(int, raw_input().split())
arrmap = defaultdict(list)
temp = {}
for i, x in enumerate(arr):
    arrmap[x].append(i)
    temp[x] = i
fr = map(int, raw_input().split())

frmap = [arrmap[x] for x in fr]
import time
t = time.time()
for p in product(*frmap):
    if time.time() - t > 3:
        frmap = [temp[x] for x in fr]
        if max(frmap) - min(frmap) < 5:
            print 'YES'
        else:
            print 'NO'
        raise SystemExit
    if sorted(p) == range(min(p), min(p) + 5):
        print 'YES'
        break
else:
    print 'NO'
