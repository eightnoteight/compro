
def main():
    from sys import stdin

    try:
        range = xrange
    except NameError:
        pass
    inp = iter(stdin.readlines())

    for x in range(int(inp.next())):
        # code...
        inp.next()
        a, plus, b, equ, c = inp.next().split()
        try:
            a = int(a)
        except ValueError:
            b = int(b)
            c = int(c)
            a = c-b
            print('{} {} {} {} {}'.format(a, plus, b, equ, c))
            continue
        try:
            b = int(b)
        except ValueError:
            c = int(c)
            b = c - a
            print('{} {} {} {} {}'.format(a, plus, b, equ, c))
            continue
        try:
            c = int(c)
        except ValueError:
            c = a + b
            print('{} {} {} {} {}'.format(a, plus, b, equ, c))
            continue

if __name__ == '__main__':
    main()
