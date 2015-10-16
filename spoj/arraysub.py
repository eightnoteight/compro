from sys import stdin

def main():
    class rmq:

        def __init__(self, arr):
            self.arr = arr
            self.tree = self.gettree()

        def gettree(self):
            arr = self.arr
            from math import log, ceil
            n = len(arr)
            tree = [0] * (2*(pow(2, int(ceil(log(n, 2))))) - 1)

            def _gettree(arr, tree, lo, hi, ind):
                if hi - lo == 1:
                    tree[ind] = arr[lo]
                    return tree[ind]
                mid = lo + (hi - lo) // 2
                tree[ind] = max(
                    _gettree(arr, tree, lo, mid, 2*ind + 1),
                    _gettree(arr, tree, mid, hi, 2*ind + 2))
                return tree[ind]
            _gettree(arr, tree, 0, len(arr), 0)
            return tree

        def updateval(self, ind, val):
            tree = self.tree
            arr = self.arr

            # in this function val and arr are not piggy backed because they
            # are used only once in an update.
            def _updateval(tree, beg, end, i, ind):
                if end - beg == 1:
                    if i == beg:
                        arr[i] = val
                        tree[ind] = val
                        return tree[ind]
                    else:
                        return tree[ind]
                if i < beg or i >= end:
                    return tree[ind]

                mid = beg + (end - beg) // 2
                tree[ind] = max(
                    _updateval(tree, beg, mid, i, 2*ind + 1),
                    _updateval(tree, mid, end, i, 2*ind + 2))
                return tree[ind]
            _updateval(tree, 0, len(arr), ind, 0)

        def query(self, lo, hi):
            def _query(tree, beg, end, qbeg, qend, ind):
                if beg >= qbeg and end <= qend:
                    return tree[ind]

                if (beg < qbeg and end <= qbeg) or (beg >= qend and end > qend):
                    return float('-inf')

                mid = beg + (end - beg) // 2
                return max(
                    _query(tree, beg, mid, qbeg, qend, 2*ind + 1),
                    _query(tree, mid, end, qbeg, qend, 2*ind + 2))

            return _query(self.tree, 0, len(self.arr), lo, hi, 0)
    inp = map(int, stdin.read().split())
    mq = rmq(inp)
    for x in xrange(1, len(inp) - inp[-1]):
        print mq.query(x, x + inp[-1]),


main()
