from sys import stdin
from itertools import imap

def main():
    stdin.readline()
    for s in imap(int, stdin):
        print("%.6f" % (1.0 - ((2**0.5)/(3*(s**0.5)))))

main()
