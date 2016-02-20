def solution(A):
    n = len(A)
    L = [-1] + A
    count = 0
    pos = (n + 1) // 2
    candidate = L[pos]
    for i in xrange(1, n + 1):
        if (L[i] == candidate):
            count = count + 1
    if count > n // 2:
        return candidate
    return -1

def main():
    print solution([1, 1, 2, 2])

main()
