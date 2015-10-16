#!/usr/bin/env python3
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
from io import StringIO
from contextlib import redirect_stdout
from random import random, randint



def main():
    n_limits = (1, 30000)
    m_limits = (1, 30000)
    output = StringIO()
    with redirect_stdout(output):
        testcases = 10
        for _ in range(testcases):
            expr_size = randint(n_limits[0], n_limits[1])
            print(expr_size)
            print(''.join(('(' if random() >= 0.5 else ')') for _ in range(expr_size)))
            m = randint(m_limits[0], m_limits[1])
            print(m)
            for _ in range(m):
                print(randint(0, expr_size))
    print(output.getvalue())
    print(output.getvalue(), file=open('brckts.testcase.in', 'w'))



main()
