for x in xrange(int(raw_input())):
	m, n = map(int, raw_input().split())
	if m <= n:
		if m%2:
			print 'R'
		else:
			print 'L'
	else:
		if n%2:
			print 'D'
		else:
			print 'U'