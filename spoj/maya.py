d = raw_input()
while d != '0':
	result = 0
	d = int(d)
	if d > 2:
		for x in xrange(d-2):
			dig = raw_input()
			dig = dig.count('-')*5 + dig.count('.')
			result += dig*360*20**(d-x-3)
		for x in xrange(2):
			dig = raw_input()
			dig = dig.count('-')*5 + dig.count('.')
			result += dig*20**(1-x)
	else:
		for x in xrange(d):
			dig = raw_input()
			dig = dig.count('-')*5 + dig.count('.')
			result += dig*20**(d-x-1)
	print result
	raw_input()
	d = raw_input()