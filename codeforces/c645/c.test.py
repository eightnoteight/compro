from random import randint, sample, seed
def main():
    # seed(int(raw_input()))
    n = randint(0, 10**5)
    k = randint(0, n - 1)
    bb = set(sample(range(n), k + 1))
    print n, k
    print ''.join(('0' if x in bb else '1') for x in xrange(n))

main()

