from sys import stdin

def main():
    nextitem = iter(stdin.read().split()).next
    for _ in xrange(int(nextitem())):
        print int(str(int(nextitem(), 7) // int(nextitem(), 7))[-int(nextitem()):])

main()
