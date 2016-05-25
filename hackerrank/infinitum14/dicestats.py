prob = [float(raw_input()) for _ in xrange(6)]
n = int(raw_input())
expx = [[(x + 1)*prob[x] for x in xrange(6)]]
expxx = [[(x + 1)*(x + 1)*prob[x] for x in xrange(6)]]
for _ in xrange(1, n):
    expx.append([(x + 1)*prob[x] for x in xrange(6)])
    expxx.append([(x + 1)*(x + 1)*prob[x] for x in xrange(6)])
    for i in xrange(6):
        for j in xrange(6):
            if i != j:
                expx[-1][i] += expx[-2][j]
                expxx[-1][i] += expxx[-2][j]
print sum(expx[-1]), sum(expxx[-1])


