from sys import stdin

def main():
    dstream = iter(map(float, stdin.read().split()))
    n = int(next(dstream))
    red = [(next(dstream), next(dstream), next(dstream)) for _ in xrange(n)]
    blue = [(next(dstream), next(dstream), next(dstream)) for _ in xrange(n)]
