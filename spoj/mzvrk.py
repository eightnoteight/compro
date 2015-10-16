#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin

def geta(x):
    return sum((i + 2)*(2**(i - 1)) for i, d in enumerate(reversed(bin(x))) if d == '1')

a, b = map(int, input().split())
print(int(geta(b) - geta(a - 1)))
