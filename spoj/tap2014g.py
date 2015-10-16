n = int(raw_input())
p = map(int, raw_input().split())
p.sort(reverse=True)
diff = [0]*(n // 2)
for x in xrange(n // 2):
    diff[x] = p[2*x] - p[2*x + 1]
diff.sort(reverse=True)
for x in xrange(1, n // 2):
    diff[x] += diff[x - 1]
e = diff[-1]
temp = False
for x in xrange(n // 2):
    if diff[x] > (e - diff[x]):
        print (n // 2 - x - 1)
        temp = True
        break
if not temp:
    print -1
