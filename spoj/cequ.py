from sys import stdin, stdout


def main():
    r = map(int, stdin.read().split())
    w = stdout.write
    for _ in xrange(r[0]):
        a, b = r[3*_ + 1], r[3*_ + 2]
        while b:
            a, b = b, a % b
        w('Case %s: %s\n' % (_ + 1, 'No' if r[3*_ + 3] % a else 'Yes'))


main()
