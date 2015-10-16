#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
from random import randrange
from random import choice as randchoice
from contextlib import redirect_stdout
from string import printable
from io import StringIO
import sys

def main():
    pchars = printable[:96] + printable[97:]
    s = StringIO()
    with redirect_stdout(s):
        n = 10**6
        print(n)
        s1 = ''.join(randchoice(pchars) for _ in range(n))
        print(s1)
        s2 = ''.join(randchoice(pchars) for _ in range(n))
        print(s2)
        m = 10**6
        print(m)
        for _ in range(m):
            l = randrange(n)
            r = randrange(l, n)
            print(l, r)
    #print(s.getvalue(), end='')
    print(s.getvalue(), end='', file=open('{}.in'.format(sys.argv[1]), 'w'))

main()
