import sys

def atstart(_):
    import atexit
    import cStringIO
    buff = cStringIO.StringIO()
    sys.stdout = buff
    @atexit.register
    def _0_():
        sys.__stdout__.write(buff.getvalue())
    return _

@atstart
def main():
    # next = iter(sys.stdin.read().split()).next
    nextint = iter(map(int, sys.stdin.read().split())).next
    for _ in xrange(nextint()):
        n, m = nextint(), nextint()
        print (m * ((n*(n + 1)) // 2)) + (((m * (m + 1)) // 2) * (((n * (n + 1)) // 2) + n))

main()
