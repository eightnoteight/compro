from math import ceil, floor


def main():
    for inp in stdin:
        key, txt = inp.split()
        key = map(int, list(key))
        kn = len(key)
        n = len(txt)
        r1 = kn + int(ceil(kn / 2.0))
        r2 = kn + int(floor(kn / 2.0))
        S = []
        ti = 0
        while ti < n:
            a


main()
