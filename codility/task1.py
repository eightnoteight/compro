# you can write to stdout for debugging purposes, e.g.
# print "this is a debug message"

def solution(L):
    # write your code in Python 2.7
    count = 0
    while L is not None:
        count += 1
        L = L.next
    return count
