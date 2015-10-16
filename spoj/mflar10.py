from sys import stdin
from itertools import imap


def main():
    output = []
    for s in imap(str.split, stdin):
        if s == ['*']:
            break
        t = s[0][0].lower()
        output.append('Y' if all(t == x[0].lower() for x in s) else 'N')
    print '\n'.join(output)

main()
