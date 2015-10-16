def main():
    from sys import stdin
    try:
        range = xrange
    except NameError:
        pass
    inp = iter(stdin.readlines())
    z = inp.next()
    while z != '0':
        x = 1
        dp = [0]*(len(z) + 1)
        dp[0] = 1
        dp[1] = 1
        lenz = len(z)
        if z[0] == '0':
            print(0)
            z = inp.next()
            continue
        for x in range(1, lenz):
            dp[x + 1] = dp[x]
            if z[x] == '0' and not ('1' <= z[x - 1] <= '2'):
                dp[lenz] = 0
                break
            elif z[x] == '0':
                continue
            if '10' <= z[x - 1:x + 1] <= '26':
                if x < lenz - 1 and z[x + 1] != '0':
                    dp[x + 1] += dp[x - 1]
                elif x == lenz - 1:
                    dp[x + 1] += dp[x - 1]
        print(dp[lenz])
        z = inp.next()

if __name__ == '__main__':
    main()
