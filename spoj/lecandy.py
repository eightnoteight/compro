import sys
for _ in xrange(int(raw_input())):
    n, c = map(int, raw_input().split())
    print('Yes' if sum(map(int, raw_input().split())) <= c else 'No')
