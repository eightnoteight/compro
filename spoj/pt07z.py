from collections import deque


n = int(raw_input())
te = [[] for x in xrange(10005)]

for x in xrange(n - 1):
    u, v = map(int, raw_input().split())
    te[u - 1].append(v - 1)
    te[v - 1].append(u - 1)
status = [True]*10005
node = 0
queue = deque([0])
while queue:
    node = queue.popleft()
    status[node] = False
    for x in te[node]:
        if status[x]:
            queue.append(x)
# print node

status = [True]*10005
depth = 0
queue = deque([None, node])
while queue:
    node = queue.popleft()
    if node is None:
        depth += 1
        queue.append(None)
        if len(queue) == 1:
            break
        else:
            continue
    status[node] = False
    for x in te[node]:
        if status[x]:
            queue.append(x)
print depth - 2
