def factorial(n):
	if n == 1:
		return 1
	return factorial(n-1)*n

t = int(raw_input())
while t:
	n = int(raw_input())
	print factorial(n)
	t-=1