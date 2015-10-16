from sys import stdin
from math import asin, degrees

def main():
    dstream = iter(map(int, stdin.read().split()))
    for t in xrange(1, next(dstream) + 1):
        try:
            print "Scenario #%s: %.2f" % (t, degrees(.5*asin(next(dstream)*9.806 / float(next(dstream)**2))))
        except ValueError:
            print "Scenario #%s: -1" % t

main()
