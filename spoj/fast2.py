#!/usr/bin/env python
# -*- encoding: utf-8 -*-


def main():
    for _ in xrange(int(raw_input())):
        print ((pow(2, int(raw_input()) + 1, 1298074214633706835075030044377087)- 1) % 1298074214633706835075030044377087)


main()
