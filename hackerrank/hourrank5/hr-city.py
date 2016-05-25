n = int(raw_input())
d = map(int, raw_input().split())
dist, coun, cdis, corn = [0]*(n + 1), [1]*(n + 1), [0]*(n + 1), [0]*(n + 1)

for x in xrange(1, n + 1):
    dist[x] = (4 * dist[x - 1] + coun[x - 1] * (16 * coun[x - 1] * d[x - 1] + 12 * cdis[x - 1]) + 8 * cdis[x - 1] + 12 * coun[x - 1] * d[x - 1] + d[x - 1]) % 1000000007
    coun[x] = (4 * coun[x - 1] + 2) % 1000000007
    cdis[x] = (4 * cdis[x - 1] + coun[x - 1] * 8 * d[x - 1] + 3 * coun[x - 1] * corn[x - 1] + 3 * d[x - 1] + 2 * corn[x - 1]) % 1000000007
    corn[x] = (2 * corn[x - 1] + 3 * d[x - 1]) % 1000000007

print dist[n]
