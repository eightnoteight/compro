for _ in xrange(int(raw_input())):
    raw_input()

    expr = raw_input().split()
    prevop = '+'
    ans = 0
    for x in expr:
        try:
            a = int(x)
            if prevop == '+':
                ans += a
            elif prevop == '*':
                ans *= a
            elif prevop == '/':
                ans //= a
            else:
                ans -= a
        except:
            prevop = x
    print(ans)
