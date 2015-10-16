#!/usr/bin/env python
# -*- encoding: utf-8 -*-


def main():
    try:
        range = xrange
        input = raw_input
    except:
        pass
    while True:
        a = input()
        ac = [0] * 26
        b = input()
        bc = [0] * 26
        for x in a:
            ac[ord(x) - 97] += 1
        for x in b:
            bc[ord(x) - 97] += 1

        print '{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}'.format(
            *[chr(97 + x) * min(ac[x], bc[x]) for x in range(26)]
        )


if __name__ == '__main__':
    try:
        main()
    except EOFError:
        pass
