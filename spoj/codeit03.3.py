#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
from sys import stdin
import datetime


def main():
    week = ['Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Saturday', 'Sunday']
    dstream = map(int, stdin.read().split())
    for _ in range(next(dstream)):
        print(week[datetime.date(
            day=next(dstream), month=next(dstream), year=next(dstream)).weekday()])


main()
