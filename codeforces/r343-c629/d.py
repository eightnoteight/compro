from math import pi

class fenwick:
    def __init__(self, n):
        sz = 1
        while n >= sz:
            sz *= 2
        self.size = sz
        self.data = [0]*sz

    def __getitem__(self, i):
        s = 0
        while i > 0:
            s = max(s, self.data[i])
            i -= i & -i
        return s

    def update(self, i, x):
        while i < self.size:
            self.data[i] = max(x, self.data[i])
            i += i & -i

def main():
    n = int(raw_input())
    arr = []
    for _ in xrange(n):
        r, h = map(int, raw_input().split())
        arr.append(r*r*h)
    nums = {x: i for i, x in enumerate(sorted(set(arr)))}
    dp = [arr[0]]
    bit = fenwick(len(nums) + 2)
    bit.update(nums[arr[0]] + 1, dp[-1])
    for x in xrange(1, len(arr)):
        dp.append(arr[x] + bit[nums[arr[x]]])
        bit.update(nums[arr[x]] + 1, dp[-1])
    print "%.10f" % (max(dp) * pi)

main()

