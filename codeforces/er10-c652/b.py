from collections import deque

def main():
    n = int(raw_input())
    arr = deque(sorted(map(int, raw_input().split())))
    out = []
    for x in xrange(n):
        if x % 2:
            out.append(arr.pop())
        else:
            out.append(arr.popleft())
    for x in xrange(1, n):
        if (x % 2 == 0 and out[x] > out[x - 1]) or ((x % 2 == 1 and out[x] < out[x - 1])):
            print 'Impossible'
            return # is this even possible?
    print ' '.join(map(str, out))

main()
