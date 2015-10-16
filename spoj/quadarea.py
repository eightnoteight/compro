#!/usr/bin/env python
# -*- encoding: utf-8 -*-
from __future__ import print_function
from math import sqrt

try:
    range = xrange
    input = raw_input
except NameError:
    pass

for _ in range(int(input())):
    a, b, c, d = map(float, input().split())
    print('{:.2f}'.format(sqrt((a*a+b*b+c*c+d*d)**2+8*a*b*c*d-2*(a**4+b**4+c**4+d**4)) / 4.0))
