from sys import stdin
cc = 0
bb = 0
bc = []
cb = []
inp = stdin.read().split()
i = 1
for _ in xrange(int(inp[0])):
    s = inp[i]
    i += 1
    ns = len(s)
    if s[0] == 'C':
        if s[-1] == 'C':
            cc += ns
        else:
            cb.append(ns)
    else:
        if s[-1] == 'B':
            bb += ns
        else:
            bc.append(ns)

if not (bc or cb):
    print max(cc, bb)
else:
    i = 0
    nbc = len(bc)
    ncb = len(cb)
    bc.sort(reverse=True)
    cb.sort(reverse=True)
    ans = bb + cc
    while i < nbc and i < ncb:
        ans += bc[i] + cb[i]
        i += 1
    if i < nbc:
        ans += bc[i]
    if i < ncb:
        ans += cb[i]
    print ans
