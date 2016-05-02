from itertools import groupby
from operator import itemgetter

class RabinKarp(object):
    def __init__(self, array):
        harr = [0]
        mul = 10007
        mod = 1000000007
        for x in array:
            harr.append((harr[-1] * mul + x) % mod)
        self.hash = harr
        self.mul = mul
        self.mod = mod


    def __getitem__(self, sl):
        assert isinstance(sl, slice)
        start, stop, _ = sl.indices(len(self.hash))
        return ((self.hash[stop] - self.hash[start] * pow(self.mul, stop - start, self.mod))) % self.mod

def main():
    n, m = map(int, raw_input().split())
    text = map(lambda x: (int(x.split('-')[0]), ord(x.split('-')[1])), raw_input().split())
    patt = map(lambda x: (int(x.split('-')[0]), ord(x.split('-')[1])), raw_input().split())
    text = [(sum(map(itemgetter(0), key_it)), key)
            for key, key_it in groupby(text, key=itemgetter(1))]
    patt = [(sum(map(itemgetter(0), key_it)), key)
            for key, key_it in groupby(patt, key=itemgetter(1))]
    count = 0
    if len(patt) == 1:
        for x, y in text:
            if y == patt[0][1] and x >= patt[0][0]:
                count += x - patt[0][0] + 1
    elif len(patt) == 2:
        for (x1, y1), (x2, y2) in zip(text, text[1:]):
            if y1 == patt[0][1] and x1 >= patt[0][0] and y2 == patt[-1][1] and x2 >= patt[-1][0]:
                count += 1
    else:
        pstart = (patt[0][0] << 8) | patt[0][1]
        pend = (patt[-1][0] << 8) | patt[-1][1]
        text = [(x << 8) | y for x, y in text]
        patt = [(x << 8) | y for x, y in patt[1:-1]]
        txt_harr = RabinKarp(text)
        pat_harr = RabinKarp(patt)
        patt_t = len(patt)
        text_t = len(text)
        for x, y in zip(xrange(len(text) + 1), xrange(patt_t, len(text) + 1)):
            if pat_harr[0: y - x] == txt_harr[x: y] and x > 0 and y < text_t:
                if text[x - 1] & 255 == pstart & 255 and text[y] >> 8 >= pend >> 8:
                    count += 1
    print count


main()
