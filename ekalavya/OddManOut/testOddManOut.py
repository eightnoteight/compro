import argparse
from itertools import count as rangeinf
import sys


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "-i", "--input", help="input filename",
        type=argparse.FileType('r'), default=sys.stdin)
    parser.add_argument(
        "-o", "--output", help="output filename",
        type=argparse.FileType('w'), default=sys.stdout)
    parser.add_argument(
        "-l", "--log", help="log filename",
        type=argparse.FileType('w'), default=sys.stderr)
    args = parser.parse_args()
    finp, fout, ferr = args.input, args.output, args.log
    arr = map(int, finp.read().split())
    output = OddManOut(arr)
    for i, x, y in zip(rangeinf(1), output[::2], output[1::2]):
        print("Sequence {} from {} to {}".format(i, x, y))
        print("Sequence {} from index {} to index {}".format(i, x, y))
    finp.close()
    fout.close()
    ferr.close()



def OddManOut(arr):
    a

if __name__ == '__main__':
    main()
5XrM8&uSdha7
