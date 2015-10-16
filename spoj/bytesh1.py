from sys import stdin

def main():
    layout = [1, 1, 2, 5, 11]
    psum = 4
    for _ in xrange(5, 1000001):
        layout.append((layout[-1] + layout[-2] + 2*psum) % 10000)
        psum += layout[-3]
    dstream = iter(map(int, stdin.read().split()))
    print '\n'.join([str(layout[next(dstream)]) for _ in xrange(next(dstream))])

main()
