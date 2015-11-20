#!/usr/bin/env python

class defaultlist(object):
    def __init__(self, factory, data=0):
        self.factory = factory
        self.list = []
        self.data = data

    def __getitem__(self, x):
        if x >= len(self.list):
            self.list.extend([self.factory() for _ in range(len(self.list), x + 1)])
        return self.list[x]

    def __repr__(self):
        return str(self)

    def __str__(self):
        return ''.join([
            '(', str(self.data), ')',
            '[', ', '.join([str(x) for x in self.list] + ['…']), ']'])

    def __setitem__(self, x, v):
        if x >= len(self.list):
            self.list.extend([self.factory() for _ in range(len(self.list), x + 1)])
        self.list[x] = v

def main():
    factory = lambda: defaultlist(factory)
    list_of_lists = defaultlist(factory)
    print(list_of_lists[0])
    list_of_lists[0][3].data = 20
    print(list_of_lists[0])


main()
