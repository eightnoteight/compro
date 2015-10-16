from math import log
for _ in xrange(int(raw_input())):
    k = int(raw_input())
    lq = int(log(k + 1, 2))
    lr = bin(k + 1 - (1 << lq))[2:]
    print '{0:5>{1}}'.format(lr.replace('0', '5').replace('1', '6'), lq)
