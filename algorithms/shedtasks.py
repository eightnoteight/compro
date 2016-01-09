from heapq import heappush, heappop, heapify


class Scheduler(object):
    def __init__(self):
        self.heap_a = []
        self.heap_b = []
        self.useless_a = 0
        self.useless_b = 0
        self.expiration = float('-inf')

    def relieve_tasks(self):
        while self.heap_a and (self.heap_a[0][2] is None or self.heap_a[0][0] < self.expiration):
            item = heappop(self.heap_a)
            if item[2] is not None:
                self.useless_b += 1
                item[2][2] = None
            else:
                self.useless_a -= 1

    def pushTask(self, task, timestamp, priority):
        self.relieve_tasks()
        item_a = [timestamp, task, None]
        item_b = [priority, task, None]
        item_a[2], item_b[2] = item_b, item_a
        heappush(self.heap_a, item_a)
        heappush(self.heap_b, item_b)
        if 2*self.useless_a > len(self.heap_a):
            self.heap_a = [x for x in self.heap_a if x[2] is not None]
            self.useless_a = 0
            heapify(self.heap_a)
        if 2*self.useless_b > len(self.heap_b):
            self.heap_b = [x for x in self.heap_b if x[2] is not None]
            self.useless_b = 0
            heapify(self.heap_b)

    def popOldTask(self):
        self.relieve_tasks()
        while True:  # raises IndexError on empty heap
            task = heappop(self.heap_a)
            if task[2] is not None:
                task[2][2] = None
                self.useless_b += 1
                return task[1], task[0], task[2][0]
            else:
                self.useless_a -= 1

    def popImpTask(self):
        self.relieve_tasks()
        while True:  # raises IndexError on empty heap
            task = heappop(self.heap_b)
            if task[2] is not None:
                task[2][2] = None
                self.useless_a += 1
                return task[1], task[2][0], task[0]
            else:
                self.useless_b -= 1

def main():
    # sanity tests
    sched = Scheduler()
    sched.pushTask("task_a", 1, 1)
    sched.pushTask("task_b", 2, 0)
    sched.pushTask("task_c", 3, 1)
    sched.pushTask("task_d", 4, 0)
    sched.pushTask("task_e", 5, 1)
    sched.expiration = 3
    print sched.popImpTask()
    print sched.popOldTask()
    print sched.popOldTask()

if __name__ == '__main__':
    main()
