from itertools import combinations


def dist(((x1, y1), (x2, y2))):
    return ((x2 - x1)**2 + (y2 - y1)**2)**0.5

def main():
    pts = [map(int, raw_input().split()) for _ in xrange(int(raw_input()))]
    xaxis = sorted([pt for pt in pts if pt[0] == 0])
    yaxis = sorted([pt for pt in pts if pt[1] == 0])
    if not xaxis:
        print "{:.6f}".format(abs(yaxis[0][0] - yaxis[-1][0]))
    elif not yaxis:
        print "{:.6f}".format(abs(xaxis[0][1] - xaxis[-1][1]))
    else:
        print "{:.6f}".format(max(map(dist, combinations([
            xaxis[0], xaxis[-1], yaxis[0], yaxis[-1]], 2))))


main()
