for _ in xrange(int(raw_input())):
    n = int(raw_input())
    area = map(int, raw_input().split())
    spot = map(int, raw_input().split())
    towers = []
    for x, y in zip(area, spot):
        towers.append(x - y)
        towers.append(y - 1)
    status = 0
    for x in xrange(len(towers)):
        if towers[x]:
            if status == 0:
                status = 1
            elif towers[x] == 1:
                status = 0
            else:
                status = 1
    print ['First', 'Second'][1 - status]
