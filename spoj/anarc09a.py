#!/usr/bin/python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin

def main():
    from sys import stdin
    from math import ceil
    for expr in stdin.read().split():
        if expr[0] == '-':
            break
        stack = []
        for x in expr.strip():
            if x == '{':
                stack.append(True)
            else:
                if stack and stack[-1]:
                    stack.pop()
                else:
                    stack.append(False)
        print int(ceil(stack.count(True) / 2.0) + ceil(stack.count(False) / 2.0))

main()
