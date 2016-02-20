# you can write to stdout for debugging purposes, e.g.
# print "this is a debug message"

def solution(arr):
    # write your code in Python 2.7
    des = [0]
    for x in xrange(1, len(arr)):
        diff = arr[x - 1] - arr[x]
        if diff > 0:
            des.append(des[-1] + diff)
        else:
            des.append(0)
    asc = [0]
    for x in xrange(len(arr) - 2, -1, -1):
        diff = arr[x + 1] - arr[x]
        if diff > 0:
            asc.append(asc[-1] + diff)
        else:
            asc.append(0)
    md = -1
    # print des, asc
    for d, a in zip(des, reversed(asc)):
        if d > 0 and a > 0:
            md = max(md, min(d, a))
    return md


def main():
    print solution(map(int, raw_input().split()))

main()
