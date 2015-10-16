from sys import stdin, stdout


def main():
    r = map(int, stdin.read().split())
    w = stdout.write
    for _ in range(next(r)):
        a, b = next(r), next(r)
        while b:
            a, b = b, a % b
        w('Case %s: %s\n' % (_ + 1, 'No' if next(r) % a else 'Yes'))


main()
