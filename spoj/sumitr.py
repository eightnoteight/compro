import sys;s=sys.stdin;q=int;m=max;z=s.readlines();z.pop(0);k=f=0;l=[0]*102
for y in z:
	if k is 0:
		if f|0:print(m(l))
		l=[0]*102;f=k=q(y);continue
	t=map(q,y.split())
	for x in range(len(t)-1,-1,-1):l[x]=m(l[x]+t[x],l[x-1]+t[x])
	k-=1
print(m(l))
