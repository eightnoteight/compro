def arison(x, y):
    if x[1] > y[1]:
        return -1
    if x[1] < y[1]:
        return 1
    if x[0] < y[0]:
        return -1
    if x[0] > y[0]:
        return 1
    return 0
inp = []
while True:
    try:
        tmp = raw_input().split()
        tmp[1] = int(tmp[1])
        inp.append(tmp)
    except EOFError:
        break
inp.sort(cmp=arison)
for x in xrange(len(inp)):
    print (inp[x][0])
