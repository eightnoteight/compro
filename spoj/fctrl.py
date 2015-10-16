def zerocount(a):
	s = 0
	i = 5
	t = a/i
	while t:
		s += t
		i *= 5
		t = a/i
	return s

for x in xrange(int(raw_input())):
	print zerocount(int(raw_input()))