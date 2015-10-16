# actually this one is the efficient one
# but spoj is accepting the ineffiecient
# sorting solution


from heapq import heapify, heappop


def inverse(x):
    return -int(x)


for x in xrange(int(raw_input())):
    need, friends = map(inverse, raw_input().split())
    stamps = map(inverse, raw_input().split())
    heapify(stamps)
    borrowed = 0
    count = 0
    while borrowed > need and stamps:
        borrowed += heappop(stamps)
        count += 1

    print('Scenario #%s' % str(x + 1))

    if borrowed <= need:
        print(count)
    else:
        print('impossible')
    print('')
