def main():
    n, _ = map(int, raw_input().split())
    countries = [float('inf')]*n
    for ss in map(int, raw_input().split()):
        countries[ss] = 0
    for x in xrange(1, n):
        countries[x] = min(countries[x], countries[x - 1] + 1)
    for x in xrange(n - 2, -1, -1):
        countries[x] = min(countries[x], countries[x + 1] + 1)
    print max(countries)

main()


