
# better approach. complexity: O(log(n))
def countzeros_vb(n):
    count, c5 = 0, 5
    while c5 <= n:
        count += (n // c5)
        c5 *= 5
    return count

def main():
    m = int(raw_input())
    arr = []
    for x in xrange(500000):
        if countzeros_vb(x) == m:
            arr.append(x)
    print len(arr)
    print ' '.join(map(str, arr))

main()
