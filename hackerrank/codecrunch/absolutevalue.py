from heapq import heappush, heappop

class MaxHeap(object):
    def __init__(self, iterable=None):
        self.heap = iterable or []

    def push(self, x):
        heappush(self.heap, -x)

    def pop(self):
        return -heappop(self.heap)

    def top(self):
        return -self.heap[0]

    def __bool__(self):
        return bool(self.heap)

class MinHeap(object):
    def __init__(self, iterable=None):
        self.heap = iterable or []

    def push(self, x):
        heappush(self.heap, x)

    def pop(self):
        return heappop(self.heap)

    def top(self):
        return self.heap[0]

    def __bool__(self):
        return bool(self.heap)

    def __len__(self):
        return len(self.heap)


def main():
    n = int(input())
    arr = list(map(int, input().split()))
    q = int(input())
    qur = list(map(int, input().split()))
    poshep = MinHeap([x for x in arr if x >= 0])
    posadd, possum = 0, sum(poshep)
    neghep = MaxHeap([x for x in arr if x < 0])
    negadd, negsum = 0, sum(neghep)
    for x in qur:
        if x < 0:
            posadd += abs(x)
            possum += len(poshep)*abs(x)
            negadd += abs(x)
            negsum += len(neghep)*abs(x)
            while poshep and poshep.top() + posadd < 0:
                node = heappop(poshep) + posadd
                heappush(neghep, -node + negadd)
        else:
            pass




