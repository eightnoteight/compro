from sys import stdin

def main():
    nextitem = iter(stdin.read().split()).next
    s1, s2 = nextitem(), nextitem()
    k = -len(s2)
    count = 0
    while True:
        k = s1.find(s2, k + len(s2))
        if k == -1:
            break
        count += 1
    print count

main()
