from collections import deque
from collections import defaultdict


def main():
    for _ in xrange(int(raw_input())):
        n, k = map(int, raw_input().split())
        Q = deque()
        words = defaultdict(int)
        mc = 0
        mw = 'z'*9
        print 'Case %d:' % (_ + 1)
        for x in xrange(n):
            s = raw_input()
            Q.append(s)
            if len(Q) > k:
                if len(Q) > 1 and Q[0] == Q[-1]:
                    Q.popleft()
                else:
                    r = Q.popleft()
                    words[r] -= 1
                    words[s] += 1
                    if words[r] == 0:
                        del words[r]
                    mc = 0
                    for x in words:
                        if (words[x] > mc) or (words[x] == mc and x < mw):
                            mw, mc = x, words[x]
            else:
                words[s] += 1
                if (words[s] > mc) or (words[s] == mc and s < mw):
                    mw, mc = s, words[s]
            print mw, mc


main()
