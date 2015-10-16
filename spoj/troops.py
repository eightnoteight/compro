from operator import itemgetter
from bisect import bisect_right as bisect
def main():
    for _ in xrange(int(raw_input())):
        troops = [map(int, raw_input().split()) for _ in xrange(int(raw_input()))]
        troops.sort(key=lambda x: (x[2], ), reverse=True)
        time = [0]
        arr = [0]
        for x in sorted(set(map(itemgetter(1), troops))):
            time.append(0)
            arr.append(x)
            k = x
            while troops and k and troops[-1][1] == x:
                c, t, s = troops.pop()
                assert t == x
                time[-1] += min(c, k)*s
                k -= min(c, k)
                print time, arr
            time[-1] += time[bisect(arr, k) - 1]
            time[-1] = max(time[-1], time[-2])
        print time[-1]



main()
