from sys import stdin

def main():
    nextitem = iter(stdin.read().split()).next
    boys = []
    girls = []
    for _ in xrange(int(nextitem())):
        g, ai, bi = nextitem(), int(nextitem()), int(nextitem())
        if g == 'M':
            boys.append((ai, bi))
        else:
            girls.append((ai, bi))
    ans = 0
    for x in xrange(1, 367):
        b, g = 0, 0
        for ai, bi in boys:
            if ai <= x <= bi:
                b += 1
        for ai, bi in girls:
            if ai <= x <= bi:
                g += 1
        ans = max(min(b, g), ans)
    print ans*2

main()
