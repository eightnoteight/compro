from operator import itemgetter

def main():
    n, k = map(int, raw_input().split())
    arr = sorted(zip(map(int, raw_input().split()), xrange(n)))
    rounds_completed = 0
    cn = n
    for i, (val, pos) in enumerate(arr):
        diffrounds = val - rounds_completed
        extrarounds = k // cn  # + (pos >= k % cn)
        rounds_completed += min(diffrounds, extrarounds)
        k -= cn*min(diffrounds, extrarounds)
        arr[i] = (diffrounds - min(diffrounds, extrarounds), pos)
        if arr[i][0] == 0:
            cn -= 1
    arr.sort(key=itemgetter(1))
    out = []
    for x in xrange(n):
        if arr[x][0] > 0 and k > 0:
            arr[x] = (arr[x][0] - 1, arr[x][1])
            k -= 1
        elif k == 0:
            for val, pos in arr[x: ] + arr[: x]:
                if val:
                    out.append(pos + 1)
            break
    if out:
        print ' '.join(map(str, out))
    else:
        print -1

main()


