from sys import stdin

def main():
    nextitem = iter(map(int, stdin.read().split())).next
    n, a, b, c = nextitem(), nextitem(), nextitem(), nextitem()
    # print n, a, b, c
    glass1 = max((n - b + 1) // (b - c), 0)
    while n - glass1*(b - c) >= b:
        glass1 += 1
    plass1 = (n - glass1*(b - c)) // a
    plass2 = n // a
    glass2 = max((n - plass2*a - b + 1) // (b - c), 0)
    while n - glass2*(b - c) - plass2*a >= b:
        glass2 += 1
    # print locals().items()
    print max(glass1 + plass1, glass2 + plass2) #, glass1, plass1, glass2, plass2

main()
