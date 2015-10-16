fof = {}
keys = []
for x in xrange(int(raw_input())):
	ll = raw_input().split()
	fof[ll[0]] = True
	keys.extend(ll[2:])
count = 0
for x in keys:
	if x not in fof:
		count += 1
		fof[x] = True
print count