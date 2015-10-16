n = int(raw_input())
while n != -1:
    if (n - 1) % 3:
        print 'N'
    else:
        c = (n - 1) // 3
        if round((1 + ((1 + 4*c)**0.5)) / 2, 6).is_integer():
            print 'Y'
        else:
            print 'N'
    n = int(raw_input())
