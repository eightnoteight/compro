from sys import stdin

def main():
    dstream = iter(stdin.read().split())
    n, m = int(next(dstream)), int(next(dstream))
    s = next(dstream)
    ninja_art_summanning_jutsu = [[c, []] for c in 'abcdefghijklmnopqrstuvwxyz']
    for i, ch in enumerate(s):
        ninja_art_summanning_jutsu[ord(ch) - ord('a')][1].append(i)
    for _ in xrange(m):
        x, y = next(dstream), next(dstream)
        for typ in ninja_art_summanning_jutsu:
            if typ[0] == x:
                typ[0] = y
            elif typ[0] == y:
                typ[0] = x
    final_string = [0]*n
    for ch, arr in ninja_art_summanning_jutsu:
        for x in arr:
            final_string[x] = ch
    print ''.join(final_string)

main()
