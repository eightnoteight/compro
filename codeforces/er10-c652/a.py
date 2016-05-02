def main():
    h1, h2 = map(int, raw_input().split())
    a, b = map(int, raw_input().split())
    h = 0
    time = 14
    pos = h1
    while True:
        if 10 <= time < 22:
            pos += a
        else:
            pos -= b
        h += 1
        time += 1
        time %= 24
        # print time, h, pos
        if pos >= h2:
            print h // 24
            break
        if h > 1000000:
            print -1
            break

main()
