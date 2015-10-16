def extract0(a):
    return a[0]


def extract1(a):
    return a[1]


while True:
    n = int(raw_input())
    aray = []
    strings = []
    answers = []
    for x in xrange(n):
        strings.append([raw_input(), x])
        tmp = map(int, strings[x][0].split())
        tmp.append(x)
        aray.append(tmp)
        answers.append(0)
    aray.sort(key=extract0)
    for x in xrange(n):
        answers[aray[x][2]] = x
    aray.sort(key=extract1)
    for x in xrange(n):
        answers[aray[x][2]] = min(n-1-x, answers[aray[x][2]])
    strings.sort(key=extract0)
    lastlist = [0]
    for x in xrange(1, n):
        if strings[x][0] == strings[x-1][0]:
            lastlist.append(strings[x][1])
        else:
            minimum = answers[strings[lastlist[0]][1]]
            for x in xrange(1, len(lastlist)):
                if minimum > answers[strings[lastlist[x]][1]]:
                    minimum = answers[strings[lastlist[x]][1]]
            for x in xrange(0, len(lastlist)):
                answers[strings[lastlist[x]][1]] = minimum
            lastlist = [x]
            x = x + 1
    minimum = answers[strings[lastlist[0]][1]]
    for x in xrange(1, len(lastlist)):
        if minimum > answers[strings[lastlist[x]][1]]:
            minimum = answers[strings[lastlist[x]][1]]
    for x in xrange(0, len(lastlist)):
        answers[strings[lastlist[x]][1]] = minimum
    lastlist = [x]

    for x in xrange(n):
        print answers[x],
    print ''
    try:
        raw_input()
    except EOFError:
        break
