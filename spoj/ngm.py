#!/usr/bin/env python
# -*- encoding: utf-8 -*-

try:
    input = raw_input
except NameError:
    pass


t = int(input())
if t % 10:
    print(1)
    print(t % 10)
else:
    print(2)
