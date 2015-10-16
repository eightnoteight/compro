from sys import stdin
from itertools import imap

def main():
	def encode2(n):
		a = [9, 8, 7, 6, 5, 4, 3, 2]
		s = []
		for x in a:
			while n % x == 0:
				s.append(str(x))
				n //= x
		if n > 1:
			return
		return ''.join(reversed(s))
	def encode(n):
		if n == 0:
			return 10
		if n < 10:
			return n
		s = []
		c = [0, 0, 0, 0]
		while n % 2 == 0:
			c[0] += 1
			n /= 2
		while n % 3 == 0:
			c[1] += 1
			n /= 3
		while n % 5 == 0:
			c[2] += 1
			n /= 5
		while n % 7 == 0:
			c[3] += 1
			n /= 7
		if n > 1:
			return
		s.append('9'*(c[1] // 2))
		s.append('8'*(c[0] // 3))
		s.append('7'*c[3])
		c[1] %= 2
		c[0] %= 3
		if c[1] and c[0]:
			s.append('6')
			c[1] -= 1
			c[0] -= 1
		s.append('5'*c[2])
		if c[0] == 2:
			c[0] = 0
			s.append('4')
		if c[1] == 1:
			c[1] = 0
			s.append('3')
		if c[0] == 1:
			c[0] = 0
			s.append('2')
		return ''.join(reversed(s))
	#for _ in xrange(int(raw_input())):
	#	print encode(int(raw_input())) or '-1'
	stdin.readline()
	print '\n'.join(imap(encode, imap(int, stdin)))

main()
