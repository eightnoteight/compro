from sys import stdin
from math import sqrt

def main():
    nextitem = iter(map(int, stdin.read().split())).next
    for t in xrange(1, 1 + nextitem()):
        n = nextitem()
        sx, sy, sz, svx, svy, svz = 0, 0, 0, 0, 0, 0
        for _ in xrange(n):
            x, y, z, vx, vy, vz = [nextitem() for _ in xrange(6)]
            sx += x
            sy += y
            sz += z
            svx += vx
            svy += vy
            svz += vz
        numer, denom = -(sx * svx + sy * svy + sz * svz), svx**2 + svy**2 + svz**2
        if denom == 0:
            dmin = sqrt(sx**2 + sy**2 + sz**2) / float(n)
            print 'Case #%d: %.8f %.8f' % (t, dmin, 0)
        else:
            time = round(numer / float(denom), 8)
            if time < 0:
                dmin = sqrt(sx**2 + sy**2 + sz**2) / float(n)
                print 'Case #%d: %.8f %.8f' % (t, dmin, 0)
            else:
                dmin = sqrt((time * svx + sx)**2 + (time * svy + sy)**2 + (time * svz + sz)**2) / float(n)
                print 'Case #%d: %.8f %.8f' % (t, dmin, time)

main()


