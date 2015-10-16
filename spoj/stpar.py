def is_revsorted(a):
    t = a[0]
    for x in xrange(1, len(a)):
        if t <= a[x]:
            return False
        t = a[x]
    return True


def is_sorted(a):
    t = a[0]
    for x in xrange(1, len(a)):
        if a[x] <= t:
            return False
        t = a[x]
    return True


n = int(raw_input())
while n != 0:
    trucks = map(int, raw_input().split())
    stack = []
    needed = 1
    for x in xrange(n):
        if trucks[x] == needed:
            needed += 1
        else:
            stack.append(trucks[x])
        while stack and stack[-1] == needed:
            stack.pop()
            needed += 1
    if needed == n + 1:
        print('yes')
    else:
        print('no')
    n = int(raw_input())
