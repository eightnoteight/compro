from sys import stdin

def main():
    nextitem = iter(stdin.read().split()).next
    for _ in xrange(int(nextitem())):
        c10 = (int(nextitem(), 7) // int(nextitem(), 7)) % pow(7, int(nextitem()))
        arr = bytearray()
        while c10:
            c10, c = divmod(c10, 7)
            arr.append(str(c))
        print arr[::-1].lstrip('0') or '0'

main()
