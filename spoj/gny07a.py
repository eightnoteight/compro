for testcases in range(int(raw_input())):
    # problem solution
    a, b = raw_input().split()
    a = int(a)
    print '{} {}{}'.format(testcases + 1, b[:a - 1], b[a:])
