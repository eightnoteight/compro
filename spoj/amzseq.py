ct = [1, 3, 7]
for x in xrange(22):
    ct.append(2*ct[-1] + ct[-2])
print ct[int(raw_input())]
