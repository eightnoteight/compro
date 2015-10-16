#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,bad-builtin,missing-docstring
from sys import stdin


def identifier(s):
    if '_' == s[0] or s[0].isupper() or s[-1] == '_' or (
            not s.replace('_', '').isalpha()) or '__' in s:
        return 2
    underscore = False
    caps = False
    if '_' in s:
        underscore = True

    if s.lower() != s:
        caps = True

    if underscore and caps:
        return 2
    elif underscore:
        return 0
    else:
        return 1


def javaConvertor(s):
    conv_s = []
    change_ahead = False
    for char in s:
        if change_ahead:
            change_ahead = False
            conv_s.append(char.upper())
        elif char == '_':
            change_ahead = True
        else:
            conv_s.append(char)

    return ''.join(conv_s)


def cpp_convertor(s):
    conv_s = []
    for char in s:
        if char.isupper():
            conv_s.append('_')
            conv_s.append(char.lower())
        else:
            conv_s.append(char)

    return ''.join(conv_s)


def error(_):
    return 'Error!'


def main():
    func = [javaConvertor, cpp_convertor, error]
    for var in stdin.read().split():
        print func[identifier(var)](var)


main()
