#!/usr/bin/python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
from sys import stdin
print "\n".join(["Case {}, N = {}, # of different labelings = {}".format(c + 1, int(n), pow(int(n), int(n) - 2)) for c, n in enumerate(stdin.read().split()[:-1])])
