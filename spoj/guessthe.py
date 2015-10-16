from sys import stdin


def main():
    def gcd(x, y):
        while y:
            x, y = y, x % y
        return x


    def the_number(s):
        if s[0] == 'N':
            return '-1'
        number = 1
        for i, x in enumerate(s):
            if x == 'Y':
                number *= (i + 1) // gcd(number, i + 1)

        for i, x in enumerate(s):
            if x == 'N' and number % (i + 1) == 0:
                return '-1'
        return str(number)

    lines = stdin.read().split()
    lines.pop()
    out = []
    for s in lines:
        out.append(the_number(s))
    print ('\n'.join(out))


main()
