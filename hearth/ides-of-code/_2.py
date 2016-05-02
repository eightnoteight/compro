ans = [0]*10
lx = 2
last = ''
while True:
    x = raw_input()
    x = x.split()
    # print len(x[0]) >= lx + 1
    if len(x) == 3 and len(x[0]) >= lx + 1:
        print last
        lx = len(x[0])
    if len(x) == 3:
        last = ' '.join(x)
    # print last
