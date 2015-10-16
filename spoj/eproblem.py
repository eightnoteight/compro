from math import log
def f(x):
    s=''
    if x==0: return '0'
    while x>0:
        s+='2+' if 1<x<4 else '2({})+'.format(f(int(log(x,2))));x-=2**int(log(x,2))
    return s[:-1]
try:
    while 1: print f(input())
except: pass
