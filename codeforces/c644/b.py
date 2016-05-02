import atexit
import cStringIO
import sys
from collections import deque

obuff = cStringIO.StringIO()
sys.stdout = obuff

@atexit.register
def write():
    sys.__stdout__.write(obuff.getvalue())

def main():
    nextint = iter(map(int, sys.stdin.read().split())).next
    n, b = nextint(), nextint()
    proc, queue = 0, deque([])
    ql = 0
    for _ in xrange(n):
        t, d = nextint(), nextint()
        while proc <= t and queue:
            tx, dx = queue.popleft()
            if tx == -1:
                print -1,
            else:
                proc = max(proc, tx) + dx
                print proc,
                ql -= 1
        if ql < b:
            queue.append((t, d))
            ql += 1
        else:
            queue.append((-1, -1))
    while queue:
        tx, dx = queue.popleft()
        if tx == -1:
            print -1,
        else:
            proc = max(proc, tx) + dx
            print proc,

main()

