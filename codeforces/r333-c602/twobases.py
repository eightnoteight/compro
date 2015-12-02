n, bx = map(int, raw_input().split())
x = map(int, raw_input().split())
m, by = map(int, raw_input().split())
y = map(int, raw_input().split())

numx, numy = 0, 0
for e, v in enumerate(reversed(x)):
    numx += v*(bx**e)
for e, v in enumerate(reversed(y)):
    numy += v*(by**e)

if numx < numy:
    print '<'
elif numx > numy:
    print '>'
else:
    print '='
