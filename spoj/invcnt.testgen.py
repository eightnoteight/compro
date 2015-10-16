#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
from random import randrange
from io import StringIO
from contextlib import redirect_stdout

def main():
    output = StringIO()
    with redirect_stdout(output):
        testcases = randrange(2, 5)
        print(testcases)
        for _ in range(testcases):
            n = randrange(1, 200000)
            print(n)
            for _ in range(n):
                print(randrange(10**7))
            print()
    print(output.getvalue())
    print(output.getvalue(), file=open("invcnt.test.in", "w"))


main()
