from random import randint

n, k = randint(1, 100), randint(0, 100000)
print n, k
print ' '.join([str(randint(1, 10000)) for _ in xrange(n)])
