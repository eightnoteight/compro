c = float(raw_input())
answers = {}
while c != 0.00:
    t = 2.0
    tmp = 0.00
    try:
        print answers[c], 'card(s)'
        c = float(raw_input())
        continue
    except:
        pass
    while tmp < c:
        tmp += (1.0/t)
        t += 1
    answers[c] = int(t-2)
    print int(t-2), 'card(s)'
    c = float(raw_input())
