#!/usr/bin/env python
# -*- encoding: utf-8 -*-



#
#   WTF!!! i think there's something wrong with the 8th testcase
#   probably a crack in input format, and i'm little bit skeptical
#   about the n == 1 case...
#

try:
    range = xrange
except:
    pass

li = [[0] for x in range(15)]
for x in range(1, 15):
    p2 = 1 << (x - 1)
    for y in range(1, p2*2 - 1):
        if li[x][-1] & p2:
            li[x].append(((li[x][-1]^1) << 1) - (1 << x))
        else:
            li[x].append((li[x][-1] << 1) + 1)

for _ in range(int(raw_input().strip())):
    n, k = map(int, raw_input().strip().split())
    s = int(raw_input().strip().replace('-', '0').replace('+', '1'), 2)
    print 'Experiment #%d:' % (_ + 1)
    if n == 1:
        if s == 0:
            for i in range(k):
                print '-' if raw_input().strip() == '0' else '+'
        else:
            for i in range(k):
                raw_input()
                print '+'
        continue
    if s == (1 << n) - 2:
        s = '{0:->{1}}'.format(bin(s)[2:].replace('0', '-').replace('1', '+'), n)
        for i in range(k):
            raw_input()
            print s
    else:
        s = li[n].index(s)
        for i in range(k):
            q = int(raw_input().strip())
            print '{0:->{1}}'.format(bin(li[n][(s + q) % ((1 << n) - 1)])[2:].replace('0', '-').replace('1', '+'), n)
