#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# pylint: disable=invalid-name,missing-docstring,bad-builtin
from sys import stdin
from collections import defaultdict

def main():
    dstream = stdin.readlines()
    out = []
    for tcase in xrange(1, int(dstream[0]) + 1):
        words = dstream[tcase].split()
        counter = defaultdict(int)
        wcounter = {}
        for w in words:
            wcounter[w] = defaultdict(int)
            for ch in w:
                wcounter[w][ch] += 1
                counter[ch] += 1
        special = max(counter, key=counter.__getitem__)
        out.append('Case #%s:' % tcase)
        for w in words:
            mch = max(wcounter[w], key=wcounter[w].__getitem__)
            mc = wcounter[w][mch]
            if special == mch and len([ch for ch, i in wcounter[w].items() if i == mc]) == 1:
                out.append(w)
    print '\n'.join(out)

main()
