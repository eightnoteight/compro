from sys import stdin


def main():
    inp = map(int, stdin.read().split())
    for x in xrange(len(inp) // 6):
        count = 0
        score = 0
        if inp[6*x]:
            count += 1
            score += inp[6*x] + (inp[6*x + 3] - 1)*60*20
        if inp[6*x + 1]:
            count += 1
            score += inp[6*x + 1] + (inp[6*x + 4] - 1)*60*20
        if inp[6*x + 2]:
            count += 1
            score += inp[6*x + 2] + (inp[6*x + 5] - 1)*60*20

        print "team %d: %d, %d" % (x + 1, count, score)

main()
