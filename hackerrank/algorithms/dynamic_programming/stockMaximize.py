for _ in xrange(int(raw_input())):
    n = int(raw_input())
    arr = map(int, raw_input().split())
    peakstack = [[0, 0, float('inf')]]
    for x in arr:
        profx = [0, 0, x]
        while peakstack and x >= peakstack[-1][2]:
            node = peakstack.pop()
            profx[0] += node[0] + 1
            profx[1] += node[1] + (x - node[2])*(node[0] + 1)
        peakstack.append(profx)
    print sum([x[1] for x in peakstack])
