#!/usr/bin/env python
# -*- encoding: utf-8 -*-

a = {
    '0': 'Airborne wins.',
    '1': 'Pagfloyd wins.'
}
for _ in xrange(int(raw_input())):
    print a[raw_input().split()[1]]
