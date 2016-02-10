x = int(raw_input())

minsteps = [0, 1, 1, 1, 1, 1]
for x in xrange(6, x + 1):
    minsteps.append(min(minsteps[-5:]) + 1)
print minsteps[x]
