from collections import deque


def main():
    n, k = map(int, raw_input().split())
    arr = deque(zip(map(int, raw_input().split()), xrange(n)))
    while k and arr:
        v, p = arr.popleft()
        v -= 1
        k -= 1
        if v > 0:
            arr.append((v, p))
    if arr:
        print ' '.join([str(p + 1) for _, p in arr])
    else:
        print -1

main()


