def main():
    n, c = map(int, raw_input().split())
    scores = map(int, raw_input().split())
    time = map(int, raw_input().split())
    limak = 0
    radew = 0
    tot = 0
    for x in xrange(n):
        tot += time[x]
        limak += max(0, scores[x] - tot * c)
    tot = 0
    for x in xrange(n - 1, -1, -1):
        tot += time[x]
        radew += max(0, scores[x] - tot * c)
    if limak > radew:
        print 'Limak'
    elif radew > limak:
        print 'Radewoosh'
    else:
        print 'Tie'

main()
