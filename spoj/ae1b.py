import sys


n, k, s = map(int, raw_input().split())
l = map(int, raw_input().split())
l.sort(reverse=True)
i = 0
su = 0
while i < len(l):
    su += l[i]
    i += 1
    if su >= k*s:
        print i
        sys.exit()
