from itertools import combinations

def solve(ambots, wsums, i, k):
    if k == 0:
        return 0, []
    minf = float('-inf')
    if i == len(ambots):
        return minf, []
    for x in xrange(i, len(ambots)):
        if ambots[x] <= k:
            sans, sl = solve(ambots, wsums, x + 1, k - ambots[x])
            if (k - ambots[x]) in wsums:
                if sans == minf:
                    return ambots[x], [ambots[x]]
                sl.append(ambots[x])
                return sans + ambots[x], sl
            else:
                sans, sl = solve(ambots, wsums, x + 1, k - ambots[x])
                if sans == minf:
                    return sans, sl
                sl.append(ambots[x])
                return sans + ambots[x], sl
    return minf, []


def main():
    minf = float('-inf')
    for _ in xrange(int(raw_input())):
        m, _, n2 = map(int, raw_input().split())
        ambots = sorted(map(int, raw_input().split()), reverse=True)
        wabots = map(int, raw_input().split())
        wsums = set(sum([[sum(comb)
                          for comb in combinations(wabots, x)]
                         for x in xrange(1, 1 + n2)], []))
        ans, ansl = solve(ambots, wsums, 0, m)
        if ans == minf:
            if m in wsums:
                print 'YES'
                print
            else:
                print 'NO'
        else:
            print 'YES'
            print ' '.join(map(str, sorted(ansl)))

main()

