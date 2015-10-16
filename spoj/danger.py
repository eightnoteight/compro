from math import log


try:
    while True:
        n = raw_input().split('e')
        n = int(n[0]) * 10 ** int(n[1])
        print (1 + 2 * (n - (1 << int(log(n, 2)))))
except:
    pass
