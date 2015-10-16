from sys import stdin

def main():
    stdin.readline()
    l = map(int, stdin.read().split())
    av = sum(l) // len(l)
    ans = 0
    for x in l:
        ans += abs(x - av)
    print ans // 2

main()
