#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
# stdin = open('/tmp/spojtest.in', 'r')
from contextlib import redirect_stdout
from random import randrange, randint
from io import StringIO


def main():
    output = StringIO()
    with redirect_stdout(output):
        testcases = 10  # randrange(10)
        print(testcases)
        for _ in range(testcases):
            n = randint(0, 10)
            e = randint(0, n // 2)
            print(n)
            print(e)
            for _ in range(e):
                print('{0} {1}'.format(randrange(n), randrange(n)))
    print(output.getvalue())
    print(output.getvalue(), file=open('cam5.testcase.in', 'w'))


main()
