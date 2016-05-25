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
    print nextint()

main()
