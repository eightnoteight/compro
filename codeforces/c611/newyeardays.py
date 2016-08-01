from datetime import datetime, timedelta

def main():
    x, _, t = raw_input().split()
    x = int(x)
    cur = datetime(2016, 1, 1)
    day = timedelta(1)
    count = 0
    for _ in xrange(366):
        if t == 'week' and cur.weekday() + 1 == x:
            count += 1
        if t == 'month' and cur.day == x:
            count += 1
        cur += day
    print count

main()
