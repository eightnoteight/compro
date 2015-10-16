from itertools import imap


# counting is too complex
# i couldn't do it
# -1 -1 -1 0 0  --> 3
# -1 -1 1 0 0   --> 6

def main():
    for _ in xrange(int(raw_input())):
        raw_input()
        ans = float('-inf')
        maxans = float('-inf')
        count = 0
        for x in imap(int, raw_input().split()):
            if ans + x > ans:
                ans += x
                if ans > maxans:
                    maxans = ans
                    count = 1
                elif ans == maxans:
                    count += 1
            elif x >= ans:
                ans = x
                if ans > maxans:
                    maxans = ans
                    count = 1
                elif ans == maxans:
                    count += 1
        print maxans, count

main()
