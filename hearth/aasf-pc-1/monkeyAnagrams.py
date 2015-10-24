from sys import stdin

def main():
    dstream = iter(stdin.read().split())
    for _ in xrange(int(next(dstream))):
        s, t = set(next(dstream)), set(next(dstream))
        if s - t:
            print -1
        else:
            print len(t - s)

main()
