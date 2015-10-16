def dollars(c, d={}):
    try:
        return d[c]
    except:
        pass
    if c < 12:
        return c
    ans = max(c, dollars(c // 2, d) + dollars(c // 3, d) + dollars(c // 4, d))
    d[c] = ans
    return ans


def main():
    while True:
        print (dollars(int(raw_input())))
try:
    main()
except:
    pass
