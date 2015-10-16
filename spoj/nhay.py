try:
    while True:
        raw_input()
        pat = raw_input()
        text = raw_input()
        t = text.find(pat, 0)
        if t == -1:
            print
        while t != -1:
            print t
            t = text.find(pat, t + 1)
        print
except EOFError:
    pass

