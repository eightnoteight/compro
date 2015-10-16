memz = {}
def fib_rec_memz(n):
    try: return memz[n]
    except: pass
    if n < 2: return n
    try: memz[n - 1]
    except: memz[n - 1] = fib_rec_memz(n - 1)
    try: memz[n - 2]
    except: memz[n - 2] = fib_rec_memz(n - 2)
    memz[n] = memz[n - 1] + memz[n - 2]
    return memz[n]
for _ in xrange(int(raw_input())):
    print fib_rec_memz(int(raw_input()))
