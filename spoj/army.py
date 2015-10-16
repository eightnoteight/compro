for tests in xrange(int(raw_input())):

    raw_input()
    raw_input()
    Ga = map(int, raw_input().split())
    Ma = map(int, raw_input().split())
    maxGa = max(Ga)
    maxMa = max(Ma)
    if maxGa >= maxMa:
        print('Godzilla')
    else:
        print('MechaGodzilla')
